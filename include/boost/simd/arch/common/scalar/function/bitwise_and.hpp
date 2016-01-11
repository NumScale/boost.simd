//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITWISE_AND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITWISE_AND_HPP_INCLUDED

#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/hierarchy.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( bitwise_and_
                          , (typename T)
                          ,  bd::cpu_
                          ,  bd::scalar_<bd::unspecified_<T>>
                          ,  bd::scalar_<bd::unspecified_<T>>
                          )
  {
    BOOST_FORCEINLINE auto operator()(T const& a, T const& b) const BOOST_NOEXCEPT -> decltype(a&b)
    {
      return a&b;
    }
  };


  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( bitwise_and_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_<bd::fundamental_<A0>>
                          , bd::scalar_<bd::fundamental_<A1>>

                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 a0, A1 a1
                                   , typename std::enable_if<sizeof(A1) == sizeof(A0)>::type* = 0
                                   ) const BOOST_NOEXCEPT
    {
      using b_t = dispatch::as_integer_t<A0, unsigned>;
      return bitwise_cast<A0>(b_t(bitwise_cast<b_t>(a0) & bitwise_cast<b_t>(a1)));
    }
  };
} } }

#endif
