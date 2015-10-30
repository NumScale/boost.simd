//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/as.hpp>
#include <limits>
#include <simd_test.hpp>

STF_CASE_TPL( "Check valmax behavior"
            , (double)(float)
              (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::valmax;
  using boost::simd::Valmax;

  STF_IEEE_EQUAL(Valmax<T>()      , std::numeric_limits<T>::max());
  STF_IEEE_EQUAL(valmax( as(T{})) , std::numeric_limits<T>::max());
}
