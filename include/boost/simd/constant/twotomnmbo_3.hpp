//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TWOTOMNMBO_3_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TWOTOMNMBO_3_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Twotomnmbo_3 Twotomnmbo_3 (function template)

  Generates @c Twotomnmbo_3 (used in [cbrt](@ref cbrt-real)).

  @headerref{<boost/simd/constant/twotomnmbo_3.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Twotomnmbo_3();
      @endcode

  2.  @code
      template<typename T> auto Twotomnmbo_3( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Twotomnmbo_3 constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to

  | Type                | double                        | float                  |
  |--------------------:|:------------------------------|------------------------|
  | value               |   4.806217383937348e-06       | 4.921566601151848e-03f |

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/twotomnmbo_3.hpp>
#include <boost/simd/constant/simd/twotomnmbo_3.hpp>

#endif
