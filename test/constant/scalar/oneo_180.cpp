//==================================================================================================
/*!

  Copyright 2015 LRI UMR 7623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/oneo_180.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check oneo_180 behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::oneo_180;
  using boost::simd::Oneo_180;

  STF_TYPE_IS(decltype(Oneo_180<T>()), T);
  STF_EQUAL(Oneo_180<T>(), T(0));
  STF_EQUAL(oneo_180( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check oneo_180 behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::oneo_180;
  using boost::simd::Oneo_180;

  STF_TYPE_IS(decltype(Oneo_180<T>()), T);
  STF_IEEE_EQUAL(Oneo_180<T>(), T(1/180.0));
  STF_IEEE_EQUAL(oneo_180( as(T{}) ), T(1/180.0));
}
