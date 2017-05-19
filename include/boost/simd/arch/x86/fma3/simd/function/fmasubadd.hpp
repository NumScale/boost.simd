//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_FMASUBADD3_SIMD_FUNCTION_FMASUBADD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_FMASUBADD3_SIMD_FUNCTION_FMASUBADD_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

#if BOOST_HW_SIMD_X86_FMASUBADD3
namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( fmasubadd_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(const A0& a0, const A0& a1, const A0& a2) const BOOST_NOEXCEPT
    {
      return _mm_fmasubadddd_ps(a0, a1, a2);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( fmasubadd_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(const A0& a0, const A0& a1, const A0& a2) const BOOST_NOEXCEPT
    {
      return _mm_fmasubadddd_pd(a0, a1, a2);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( fmasubadd_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(const A0& a0, const A0& a1, const A0& a2) const BOOST_NOEXCEPT
    {
      return _mm256_fmasubadddd_ps(a0, a1, a2);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( fmasubadd_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(const A0& a0, const A0& a1, const A0& a2) const BOOST_NOEXCEPT
    {
      return _mm256_fmasubadddd_pd(a0, a1, a2);
    }
  };

} } }
#endif
#include <boost/simd/arch/x86/fmasubadd3/simd/function/correct_fmasubadd.hpp>
#endif
