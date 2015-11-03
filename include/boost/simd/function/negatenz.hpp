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
#ifndef BOOST_SIMD_FUNCTION_NEGATENZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGATENZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns x multiplied by the @ref signnz of y.

    The result is unspecified if y is @ref Nan

    @par Semantic:

    @code
    T r = negatenz(x,y);
    @endcode

    is similar to:

    @code
    T r = x*signnz(y);
    @endcode

    @par Note
    If x is non @ref Zero the result is @ref Zero. Take care that negatenz distinguish
    between the signs of T(0) and -T(0) when T is a floating type.

    @see negatenz, Mzero, is_positive, is_negative

    @return a value of same type as the inputs

**/
  template<typename T> auto negatenz(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns x multiplied by the @ref signnz of y.


      Function object tied to simd::negaten

z      @see simd::negatenz
z    **/
    const boost::dispatch::functor<tag::negatenz_> negatenz = {};
  }
} }
#endif

#include <boost/simd/function/definition/negatenz.hpp>
#include <boost/simd/arch/common/generic/function/negatenz.hpp>
#include <boost/simd/function/simd/negatenz.hpp>

#endif
