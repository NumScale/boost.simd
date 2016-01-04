//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_LOG_10_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_LOG_10_HPP_INCLUDED

#include <boost/simd/config.hpp>
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
    struct log_10_ : boost::dispatch::constant_value_<log_10_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,log_10_,boost::dispatch::constant_value_<log_10_>);
      BOOST_SIMD_REGISTER_CONSTANT(2, 0x40135d8eUL, 0x40026bb1bbb55516ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,log_10_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::log_10_,log_10);
  }

  template<typename T> BOOST_FORCEINLINE auto Log_10() BOOST_NOEXCEPT
  -> decltype(functional::log_10( boost::dispatch::as_<T>{}))
  {
    return functional::log_10( boost::dispatch::as_<T>{} );
  }
} }

#endif
