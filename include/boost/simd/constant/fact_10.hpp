//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_FACT_10_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_FACT_10_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Fact_10 Fact_10 (function template)

  Generates @c 10! that is @c 3628800

  @headerref{<boost/simd/constant/fact_10.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Fact_10();
      @endcode

  2.  @code
      template<typename T> auto Fact_10( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Fact_10 constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to @c T(3628800).

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/fact_10.hpp>
#include <boost/simd/constant/simd/fact_10.hpp>

#endif
