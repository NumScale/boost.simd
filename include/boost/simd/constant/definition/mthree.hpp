//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MTHREE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MTHREE_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct mthree_ : boost::dispatch::constant_value_<mthree_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,mthree_,boost::dispatch::constant_value_<mthree_>);
      BOOST_SIMD_REGISTER_CONSTANT(-3, 0xc0400000UL, 0xc008000000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,mthree_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mthree_,mthree);
  }

  template<typename T> BOOST_FORCEINLINE auto Mthree() BOOST_NOEXCEPT
  -> decltype(functional::mthree( boost::dispatch::as_<T>{}))
  {
    return functional::mthree( boost::dispatch::as_<T>{} );
  }
} }

#endif
