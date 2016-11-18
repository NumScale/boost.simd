//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_REC_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/constant/inveps.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_denormal.hpp>
#include <boost/simd/arch/x86/avx/simd/function/rec_raw.hpp>
#include <boost/simd/arch/x86/avx/simd/function/rec_fast.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( rec_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a00) const BOOST_NOEXCEPT
    {
      A0 a0;
      #ifndef BOOST_SIMD_NO_DENORMALS
      auto is_den = is_denormal(a00);
      auto any_is =  any(is_den);
      A0 fac;
      if (BOOST_UNLIKELY((any_is)))
      {
        fac = if_else(is_den, Inveps<A0>(), One<A0>());
        a0 *=  fac;
      }
      #endif
      a0 = refine_rec(a00, refine_rec(a00,refine_rec(a00, raw_(rec)(a00))));
      a0 =  if_else(is_eqz(a00),
                    bitwise_or(a00, Inf<A0>()),
                    a0
                   );
      #ifndef BOOST_SIMD_NO_INFINITIES
      a0 = if_else(is_inf(a00),
                      bitwise_and(a00, Zero<A0>()),
                      a0
                     );
      #endif
      #ifndef BOOST_SIMD_NO_DENORMALS
      if (BOOST_UNLIKELY((any_is))) a0 *= fac;
      #endif
      return a0;
    }
  };

} } }


#endif
