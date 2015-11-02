//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEXTPOW2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEXTPOW2_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/scalar/abss.hpp>
#include <boost/simd/function/scalar/frexp.hpp>
#include <boost/simd/function/scalar/ffs.hpp>
#include <boost/simd/function/scalar/reversebits.hpp>
#include <boost/simd/function/scalar/minusone.hpp>
#include <boost/simd/function/scalar/abs.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( nextpow2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_ < bd::unsigned_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      if (!a0) return a0;
      return sizeof(A0)*8-ffs(reversebits(a0));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( nextpow2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_ < bd::signed_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      if (!a0) return a0;
      return sizeof(A0)*8-ffs(reversebits(abss(a0)));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( nextpow2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_ < bd::floating_<A0> >
                          )
  {
    using result_t = bd::as_integer_t<A0, signed>;
    BOOST_FORCEINLINE result_t operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      A0 m;
      result_t p;
      simd::frexp(simd::abs(a0), m, p);
      return (m == Half<A0>())  ? minusone(p) :  p;
    }
  };
} } }


#endif
