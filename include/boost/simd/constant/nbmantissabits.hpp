//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_NBMANTISSABITS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_NBMANTISSABITS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the number of mantissa bits of a floating point number.

    @par Semantic:

    @code
    T r = Nbmantissabits<T>();
    @endcode

    is similar to:

    @code
    if T is integral
      r = sizeof(T)*8
    else if T is double
      r =  52;
    else if is float
      r =  23;
    @endcode

    @return The Nbmantissabits constant for the proper type
  **/
  template<typename T> T Nbmantissabits();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant nbmantissabits.

      @return The Nbmantissabits constant for the proper type
    **/
    const boost::dispatch::functor<tag::nbmantissabits_> nbmantissabits = {};
  }
} }
#endif

#include <boost/simd/constant/definition/nbmantissabits.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
