//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_EXPNIBIG_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_EXPNIBIG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant expnibig.

    @return The Expnibig constant for the proper type
  **/
  template<typename T> T Expnibig();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant expnibig.

      @return The Expnibig constant for the proper type
    **/
    const boost::dispatch::functor<tag::expnibig_> expnibig = {};
  }
} }
#endif

#include <boost/simd/constant/definition/expnibig.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
