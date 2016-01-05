//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXPONENTBITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPONENTBITS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the exponent bits of the floating input as an integer value,
    the other bits (sign and mantissa) being just masked.

    This function is not defined on integral types.

    @par Semantic:

    @code
    as_integer_t<T> r = exponentbits(x);
    @endcode

    is similar to

    @code
    as_integer_t<T> r = x&Exponentmask<T>();
    @endcode


    @return a value of the integral type associated to the input

**/
  template<typename T> auto exponentbits(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns the exponent bits of the floating input as an integer value.


      Function object tied to simd::exponentbits

      @see simd::exponentbits
    **/
    const boost::dispatch::functor<tag::exponentbits_> exponentbits = {};
  }
} }
#endif

#include <boost/simd/function/definition/exponentbits.hpp>
#include <boost/simd/arch/common/scalar/function/exponentbits.hpp>
#include <boost/simd/function/simd/exponentbits.hpp>

#endif
