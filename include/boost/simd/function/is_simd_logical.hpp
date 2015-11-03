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
#ifndef BOOST_SIMD_FUNCTION_IS_SIMD_LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_SIMD_LOGICAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    returns @ref True if each vector elements have all bits or no bit set.

    @par Semantic:

    For every parameter of type T

    @code
    logical<scalar_of_t<T>> r = is_simd_logical(x);
    @endcode

    is similar to:

    @code
    T r = all(x == Allbits || x == Zero);
    @endcode

    @see mask2logical

    @return a value of the scalar logical type associated to the parameter

**/
  template<typename T> auto is_simd_logical(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      returns @ref True if each vector elements have all bits or no bit set.


      Function object tied to simd::is_simd_logical

      @see simd::is_simd_logical
    **/
    const boost::dispatch::functor<tag::is_simd_logical_> is_simd_logical = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_simd_logical.hpp>
#include <boost/simd/arch/common/scalar/function/is_simd_logical.hpp>
#include <boost/simd/function/simd/is_simd_logical.hpp>

#endif
