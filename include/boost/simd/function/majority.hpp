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
#ifndef BOOST_SIMD_FUNCTION_MAJORITY_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAJORITY_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True if at least two inputs are not @ref Zero else False.

    @par Semantic:

    @code
    as_logical_t<T> r = majority(x,y,a2);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = (x!= 0)+(y!= 0)+(a2!= 0) >= 2;
    @endcode




    @return a logical value

**/
  template<typename T> auto majority(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True if at least two inputs are not @ref Zero else False.


      Function object tied to simd::majority

      @see simd::majority
    **/
    const boost::dispatch::functor<tag::majority_> majority = {};
  }
} }
#endif

#include <boost/simd/function/definition/majority.hpp>
#include <boost/simd/arch/common/scalar/function/majority.hpp>
#include <boost/simd/function/simd/majority.hpp>

#endif
