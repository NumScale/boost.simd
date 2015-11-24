//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_FLINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_FLINT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True or @ref False according x is a flint or not.

    @par Semantic:

    @code
    as_logical_t<T> r = is_flint(x);
    @endcode

    @par Note:

    A flint is a 'floating integer' i.e. a floating number
    representing exactly an integer value.

    Be conscious that all sufficiently great floating points values
    are flint and even are even...


    @return a logical value

**/
  template<typename T> auto is_flint(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True or @ref False according x is a flint or not.


      Function object tied to simd::is_flint

      @see simd::is_flint
    **/
    const boost::dispatch::functor<tag::is_flint_> is_flint = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_flint.hpp>
#include <boost/simd/arch/common/scalar/function/is_flint.hpp>
#include <boost/simd/function/simd/is_flint.hpp>

#endif
