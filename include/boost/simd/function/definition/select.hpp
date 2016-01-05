//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_SELECT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_SELECT_HPP_INCLUDED

#include <boost/simd/function/definition/if_else.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    using select_ = if_else_;
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::select_,select);
  }
  BOOST_DISPATCH_FUNCTION_DEFINITION(tag::select_,select);
} }

#endif
