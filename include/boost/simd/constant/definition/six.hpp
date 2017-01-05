//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_SIX_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_SIX_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct six_ : boost::dispatch::constant_value_<six_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,six_,boost::dispatch::constant_value_<six_>);
      BOOST_SIMD_REGISTER_CONSTANT(6, 0x40c00000UL, 0x4018000000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, six_)
  }

  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::six_,six);
  }

  template<typename T> BOOST_FORCEINLINE auto Six()
  BOOST_NOEXCEPT_DECLTYPE(detail::six( boost::dispatch::as_<T>{}))
  {
    return detail::six( boost::dispatch::as_<T>{} );
  }

  template<typename T> BOOST_FORCEINLINE
  auto Six(boost::dispatch::as_<T> const&) BOOST_NOEXCEPT_DECLTYPE(Six<T>())
  {
    return Six<T>();
  }
} }

#endif
