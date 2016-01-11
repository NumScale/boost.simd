//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ABSS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ABSS_HPP_INCLUDED

#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/math.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( abss_
                          , (typename T)
                          , bd::cpu_
                          , bd::generic_<bd::unsigned_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a) const BOOST_NOEXCEPT
    {
      return a;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( abss_
                          , (typename T)
                          , bd::cpu_
                          , bd::generic_<bd::floating_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a) const BOOST_NOEXCEPT
    {
      return simd::abs(a);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( abss_
                          , (typename T)
                          , bd::cpu_
                          , bd::generic_<bd::signed_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a0) const BOOST_NOEXCEPT
    {
      T a =  simd::abs(a0);
      return if_else(is_equal(a0,Valmin<T>()),Valmax<T>(),a);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( abss_
                          , (typename T)
                          , bd::cpu_
                          , bd::generic_<bd::unspecified_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a) const BOOST_NOEXCEPT
    {
      return abss(a);
    }
  };
} } }


#endif
