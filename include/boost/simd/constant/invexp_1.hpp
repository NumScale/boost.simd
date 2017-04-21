//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_INVEXP_1_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_INVEXP_1_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Invexp_1 Invexp_1 (function template)

  Generates constant 1/e.

  @headerref{<boost/simd/constant/invexp_1.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Invexp_1();
      @endcode

  2.  @code
      template<typename T> auto Invexp_1( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Invexp_1 constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to `T(0.3678794411714423215955237701614608674458111310317678)`.

  @par Requirements
  - **T** models IEEEValue
**/

#include <boost/simd/constant/scalar/invexp_1.hpp>
#include <boost/simd/constant/simd/invexp_1.hpp>

#endif
