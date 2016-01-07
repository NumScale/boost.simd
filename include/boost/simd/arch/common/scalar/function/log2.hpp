//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_LOG2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_LOG2_HPP_INCLUDED

#include <boost/simd/arch/common/detail/scalar/logarithm.hpp>
#include <boost/simd/options.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD ( log2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::arithmetic_<A0> >
                          , boost::simd::std_tag
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0
                                    , std_tag const& ) const BOOST_NOEXCEPT
    {
       return std::log2(a0);
    }
  };
} } }


#endif
