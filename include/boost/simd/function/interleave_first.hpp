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
#ifndef BOOST_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    Computes a vector from a combination of the two inputs.

    @par Semantic:

    For every parameters of types respectively T, the following code:

    @code
    T r = interleave_first(a,b);
    @endcode

    is equivalent to :

    @code
    r = [ a[0] b[0] a[1] b[1] ... a[n/2-1] b[n/2-1] ]
    @endcode

    with <tt> n = cardinal_of<T>::value </tt>


    @return a value of the same type as the parameters

**/
  template<typename T> auto interleave_first(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar

      Computes a vector from a combination of the two inputs.


      Function object tied to simd::interleave_first

      @see simd::interleave_first
    **/
    const boost::dispatch::functor<tag::interleave_first_> interleave_first = {};
  }
} }
#endif

#include <boost/simd/function/definition/interleave_first.hpp>
#include <boost/simd/arch/common/scalar/function/interleave_first.hpp>
//#include <boost/simd/arch/common/function/simd/interleave_first.hpp>

#endif
