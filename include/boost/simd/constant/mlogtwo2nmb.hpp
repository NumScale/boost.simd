//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MLOGTWO2NMB_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MLOGTWO2NMB_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Mlogtwo2nmb Mlogtwo2nmb (function template)

  Generates constant Mlogtwo2nmb, opposite of thenatural logarithm of
  [Two2nmb](@ref Two2nmb-constant) constant

  @headerref{<boost/simd/constant/mlogtwo2nmb.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Mlogtwo2nmb();
      @endcode

  2.  @code
      template<typename T> auto Mlogtwo2nmb( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Mlogtwo2nmb constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to

  | Type                | double                              | float                               |
  |--------------------:|:------------------------------------|-------------------------------------|
  | value               |  -36.043653389117156089696070315825 | -15.942385152878742116596338793538f |

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/mlogtwo2nmb.hpp>
#include <boost/simd/constant/simd/mlogtwo2nmb.hpp>

#endif
