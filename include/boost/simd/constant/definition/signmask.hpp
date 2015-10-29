//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_SIGNMASK_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_SIGNMASK_HPP_INCLUDED

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
    struct signmask_ : boost::dispatch::constant_value_<signmask_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,signmask_,boost::dispatch::constant_value_<signmask_>);

      struct value_map
      {
        template<typename X>
        static std::integral_constant<X,-127-1> value(boost::dispatch::int8_<X> const&);

        template<typename X>
        static std::integral_constant<X,-32767-1> value(boost::dispatch::int16_<X> const&);

        template<typename X>
        static std::integral_constant<X,-2147483647-1> value(boost::dispatch::int32_<X> const&);

        template<typename X>
        static std::integral_constant<X,-9223372036854775807LL-1> value(boost::dispatch::int64_<X> const&);

        template<typename X>
        static std::integral_constant<X,0x80U> value(boost::dispatch::uint8_<X> const&);

        template<typename X>
        static std::integral_constant<X,0x8000U> value(boost::dispatch::uint16_<X> const&);

        template<typename X>
        static std::integral_constant<X,0x80000000UL> value(boost::dispatch::uint32_<X> const&);

        template<typename X>
        static std::integral_constant<X,0x8000000000000000ULL> value(boost::dispatch::uint64_<X> const&);

        template<typename X>
        static brigand::single_<0x80000000UL> value(boost::dispatch::single_<X> const&);

        template<typename X>
        static brigand::double_<0x8000000000000000ULL> value(boost::dispatch::double_<X> const&);
      };

    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,signmask_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::signmask_,signmask);
  }

  template<typename T> BOOST_FORCEINLINE auto Signmask() BOOST_NOEXCEPT
  -> decltype(functional::signmask( boost::dispatch::as_<T>{}))
  {
    return functional::signmask( boost::dispatch::as_<T>{} );
  }
} }

#endif
