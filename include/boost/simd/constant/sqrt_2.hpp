//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SQRT_2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SQRT_2_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Sqrt_2 Sqrt_2 (function template)

  Generates  \f$\sqrt2\f$

  @headerref{<boost/simd/constant/sqrt_2.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Sqrt_2();
      @endcode

  2.  @code
      template<typename T> auto Sqrt_2( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Sqrt_2 constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to `T(1.4142135623730950488016887242097)`

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/sqrt_2.hpp>
#include <boost/simd/constant/simd/sqrt_2.hpp>

#endif
