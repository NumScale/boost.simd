//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CSCPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CSCPI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    cosecant of angle in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = cscpi(x);
    @endcode

    is similar to:

    @code
    T r = rec(sinpi(x));
    @endcode

    As most other trigonometric function cscpi can be called with a second optional parameter
    which is a tag on speed and accuracy (see @ref cos for further details)

    @see cscd, csc,

    @return a value of the same type as the parameter

**/
  template<typename T> auto cscpi(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      cosecant of angle in \f$\pi\f$ multiples.


      Function object tied to simd::cscpi

      @see simd::cscpi
    **/
    const boost::dispatch::functor<tag::cscpi_> cscpi = {};
  }
} }
#endif

#include <boost/simd/function/scalar/cscpi.hpp>
#include <boost/simd/function/simd/cscpi.hpp>

#endif
