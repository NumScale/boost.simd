//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NGTZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NGTZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_ngtz capabilities

    Returns @ref True if x is not greater than @ref Zero else returns @ref False.

    @par Semantic:

    @code
    as_logical_t<T> r = is_ngtz(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = !(x > 0);
    @endcode

    @par Note:

    Due to existence of @ref Nan, this is not equivalent to a call to
    @ref is_lez for floating types

  **/
  const boost::dispatch::functor<tag::is_ngtz_> is_ngtz = {};
} }
#endif

#include <boost/simd/function/scalar/is_ngtz.hpp>
#include <boost/simd/function/simd/is_ngtz.hpp>

#endif
