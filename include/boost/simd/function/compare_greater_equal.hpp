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
#ifndef BOOST_SIMD_FUNCTION_COMPARE_GREATER_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_GREATER_EQUAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns a logical scalar that is the result of the lexicographic
    test for >= on all elements of the entries

    It is probably not what you wish. Have a look to is_greater_equal.

    @par Semantic:

    For every parameters of type T0:

    @code
    as_logical_t<scalar_of_t<T0>> r = compare_greater_equal(x,y);
    @endcode

    is similar to:

    @code
      as_logical_t<scalar_of_t<T0>> r = !compare_less(y, x)
    @endcode

    @par Alias:
    @c compare_ge

    @see is_greater_equal


    @return a value of the scalar logical type associated to the parameters

**/
  template<typename T> auto compare_greater_equal(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns a logical scalar that is the result of the lexicographic
      test for >= on all elements of the entries


      Function object tied to simd::compare_greater_equal

      @see simd::compare_greater_equal
    **/
    const boost::dispatch::functor<tag::compare_greater_equal_> compare_greater_equal = {};
  }
} }
#endif

#include <boost/simd/function/definition/compare_greater_equal.hpp>
#include <boost/simd/arch/common/scalar/function/compare_greater_equal.hpp>
#include <boost/simd/function/simd/compare_greater_equal.hpp>

#endif
