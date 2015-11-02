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
#ifndef BOOST_SIMD_FUNCTION_ULPDIST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ULPDIST_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns ulp distance of the two values.

    @par Semantic:

    For any pairs of values of common type T

    @code
    T r = ulpdist(x,y);
    @endcode

    is similar to:

    @code
    T r = abs(x-y)/Eps<T>();
    @endcode

    @par Note:

    If the common type is integral  @c ulpdist is the same as @c dist

    If the common type is floating point the ulpdist is is computed,
    by the above described method.

    It is often difficult to answer to the following question: "are
    these two floating computations results similar enough?". The
    ulpdist is a way to answer which is tuned for relative errors
    estimations and peculiarly adapted to cope with the limited bits
    accuracy of floating point representations.

    The method is the following:

     - if one is Nan the result is Nan,  if both are Nans the result is 0

     - Else, properly normalize the two numbers by the same factor in a way
     that the largest of the two numbers exponents will be brought to
     zero

     - Return the absolute difference of these normalized numbers
      divided by the rounding error Eps

    The roundind error is the ulp (unit in the last place) value, i.e. the
    floating number, the exponent of which is 0 and the mantissa is all zeros
    but a 1 in the last digit (it is not hard coded that way however).
    This means \f$2^-23\f$ for float and \f$2^-52\f$ for double.

    \arg For instance if two floating numbers (of same type) have an ulpdist of
    zero that means that their floating representation are identical or they are
    both Nans.

    \arg Generally equality up to 0.5 ulp is the best that one can wish beyond
    strict equality.

    @par Examples:

    \arg Typically if a double is compared to the float representation of
    its floating conversion (they are exceptions as for fully representable
    reals) the ulpdist will be around 2^26.5 (~10^8)

    \arg The ulpdist is also roughly equivalent to the number of representable
    floating points values between two given floating points values.

    \arg  @c ulpdist(1.0,1+Eps\<double\>())==0.5
    \arg  @c ulpdist(1.0,1+Eps\<double\>()/2)==0.0
    \arg  @c ulpdist(1.0,1-Eps\<double\>()/2)==0.25
    \arg  @c ulpdist(1.0,1-Eps\<double\>())==0.5
    \arg  @c ulpdist(double(Pi\<float\>()),Pi\<double\>())==9.84293e+07

    @see ulp, Eps, eps

    @return a value of same type as the inputs

**/
  template<typename T> auto ulpdist(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns ulp distance of the two values.


      Function object tied to simd::ulpdist

      @see simd::ulpdist
    **/
    const boost::dispatch::functor<tag::ulpdist_> ulpdist = {};
  }
} }
#endif

#include <boost/simd/function/definition/ulpdist.hpp>
#include <boost/simd/arch/common/scalar/function/ulpdist.hpp>
#include <boost/simd/function/simd/ulpdist.hpp>

#endif
