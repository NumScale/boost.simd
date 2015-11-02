//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXPONENT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPONENT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the exponent of the floating input.

    @par Semantic:

    @code
    as_integer_t<T> r = exponent(x);
    @endcode

    is similar to:

    @code
    as_integer_t<T> r = ilogb(x);
    @endcode

    @par Note:

     The sign \f$ \pm \f$ , exponent e and mantissa m of a floating point entry a are related by
    \f$a = \pm m\times 2^e\f$, with m between one (included) and two (excluded).

    For integral type inputs exponent is always 0 and mantissa reduces to identity.

    @see mantissa,  frexp, ldexp

    @return a value of same type as the input

**/
  template<typename T> auto exponent(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns the exponent of the floating input.


      Function object tied to simd::exponent

      @see simd::exponent
    **/
    const boost::dispatch::functor<tag::exponent_> exponent = {};
  }
} }
#endif

#include <boost/simd/function/definition/exponent.hpp>
#include <boost/simd/arch/common/scalar/function/exponent.hpp>
#include <boost/simd/function/simd/exponent.hpp>

#endif
