//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_HALFEPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_HALFEPS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the machine epsilon.

    @par Semantic:

    @code
    T r = Halfeps<T>();
    @endcode

    is similar to:

    @code
    if T is integral
      r = T(1)
    else if T is double
      r =  pow(2, -54);
    else if T is float
      r =  pow(2.0f, -24);
    @endcode

    @return The Halfeps constant for the proper type
  **/
  template<typename T> T Halfeps();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant halfeps.

      @return The Halfeps constant for the proper type
    **/
    const boost::dispatch::functor<tag::halfeps_> halfeps = {};
  }
} }
#endif

#include <boost/simd/constant/definition/halfeps.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
