//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_SHAR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_SHAR_HPP_INCLUDED

#include <boost/simd/function/definition/shift_right.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    using shar_ = shift_right_;
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::shar_,shar);
  }
  BOOST_DISPATCH_FUNCTION_DEFINITION(tag::shar_,shar);
} }

#endif
