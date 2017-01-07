//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/cast.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include "cast_test_base.hpp"

namespace bs = boost::simd;

STF_CASE( "Check cast behavior for uint8_t" )
{
  static const std::size_t N = bs::pack<uint8_t>::static_size;

  test_val<bs::pack<uint8_t, N>>($);
  test_val<bs::pack<uint8_t, N/2>>($);
  test_val<bs::pack<uint8_t, N*2>>($);
}
