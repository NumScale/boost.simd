//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_GENERIC_REALSQRT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_GENERIC_REALSQRT_HPP_INCLUDED

#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/assert.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/is_nltz.hpp>
#include <boost/simd/function/sqrt.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( realsqrt_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(boost::simd::assert_all(is_nltz(a0)),
                       "realsqrt cannot produce complex result.");
      return sqrt(a0);
    }
  };
} } }


#endif
