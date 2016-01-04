//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_REM_PIO2_MEDIUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_REM_PIO2_MEDIUM_HPP_INCLUDED

#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, rem_pio2_medium_, boost::dispatch::elementwise_<rem_pio2_medium_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, rem_pio2_medium_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::rem_pio2_medium_,rem_pio2_medium);
  }

  BOOST_DISPATCH_FUNCTION_DEFINITION(tag::rem_pio2_medium_, rem_pio2_medium);

} }

#endif
