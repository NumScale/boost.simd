//==================================================================================================
/*!
  @file

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS
  Copyright 2015 NumScale J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_IF_ELSE_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_IF_ELSE_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, if_else_, boost::dispatch::elementwise_<if_else_>);
  }
  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, if_else_);
  }
  namespace fun
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::if_else_,if_else);
//     BOOST_DISPATCH_CALLABLE_DEFINITION(tag::if_else_,where);
//     BOOST_DISPATCH_CALLABLE_DEFINITION(tag::if_else_,select);
//     BOOST_DISPATCH_CALLABLE_DEFINITION(tag::if_else_,sel);
   }
     BOOST_DISPATCH_FUNCTION_DEFINITION(tag::if_else_,if_else);
//     BOOST_DISPATCH_FUNCTION_DEFINITION(tag::if_else_,where);
//     BOOST_DISPATCH_FUNCTION_DEFINITION(tag::if_else_,select);
//     BOOST_DISPATCH_FUNCTION_DEFINITION(tag::if_else_,sel);
} }

#endif
