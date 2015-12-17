//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_SPLAT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/as.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, splat_, boost::dispatch::elementwise_<splat_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, splat_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::splat_,splat);
  }

  template<typename T, typename A> BOOST_FORCEINLINE T splat(const A& a) BOOST_NOEXCEPT
  {
    return functional::splat(a, as_<T>());
  }
} }

#endif
