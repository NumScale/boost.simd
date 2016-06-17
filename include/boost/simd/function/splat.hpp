//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLAT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

  **/
  template<typename T, typename U> T splat(U const& x) {}
} }
#endif

#include <boost/simd/function/scalar/splat.hpp>
#include <boost/simd/function/simd/splat.hpp>

#endif
