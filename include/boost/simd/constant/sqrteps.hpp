//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SQRTEPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SQRTEPS_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Sqrteps Sqrteps (function template)

  Generates the square root of constant [Eps](@ref constant-Eps)

  @headerref{<boost/simd/constant/sqrteps.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Sqrteps();
      @endcode

  2.  @code
      template<typename T> auto Sqrteps( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Sqrteps constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c as_integer_t<T> that evaluates to

  | Type                | double                        | float          | Integral        |
  |--------------------:|:------------------------------|----------------|-----------------|
  | value               |   1.490116119384766e-08       | 3.4526698e-04f |  1              |

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/sqrteps.hpp>
#include <boost/simd/constant/simd/sqrteps.hpp>

#endif
