//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_TWOTO31_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_TWOTO31_HPP_INCLUDED

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
    struct twoto31_ : boost::dispatch::constant_value_<twoto31_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,twoto31_,boost::dispatch::constant_value_<twoto31_>);
      BOOST_SIMD_REGISTER_CONSTANT((1ULL << 31), 0x4f000000UL, 0x41e0000000000000LL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,twoto31_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::twoto31_,twoto31);
  }

  template<typename T> BOOST_FORCEINLINE auto Twoto31() BOOST_NOEXCEPT
  -> decltype(functional::twoto31( boost::dispatch::as_<T>{}))
  {
    return functional::twoto31( boost::dispatch::as_<T>{} );
  }
} }

#endif
