//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_PIX2_2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_PIX2_2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Constant used in modular computation involving \f$\pi\f$

    @par Semantic:

    For type T:

    @code
    T r = Pix2_2<T>();
    @endcode

    @return a value of type T

**/
  template<typename T> T Pix2_2();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Constant used in modular computation involving \f$\pi\f$

      Generate the  constant pix2_2.

      @return The Pix2_2 constant for the proper type
    **/
    const boost::dispatch::functor<tag::pix2_2_> pix2_2 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/pix2_2.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
