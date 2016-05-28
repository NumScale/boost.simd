//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ne.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" ne integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ne;
  using r_t = decltype(ne(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(ne(bs::One<T>(), bs::One<T>()), r_t(false));
  STF_EQUAL(ne(bs::One<T>(),bs::Zero<T>()), r_t(true));
  STF_EQUAL(ne(bs::Zero<T>(), bs::Zero<T>()), r_t(false));
} // end of test for integer_

STF_CASE_TPL (" ne real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ne;
  using r_t = decltype(ne(T(), T()));

  // return type conformity test
 STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(ne(bs::Inf<T>(), bs::Inf<T>()), r_t(false));
  STF_EQUAL(ne(bs::Minf<T>(), bs::Minf<T>()), r_t(false));
  STF_EQUAL(ne(bs::Nan<T>(), bs::Nan<T>()), r_t(true));
  STF_EQUAL(ne(bs::One<T>(),bs::Zero<T>()), r_t(true));
  STF_EQUAL(ne(bs::Zero<T>(), bs::Zero<T>()), r_t(false));
} // end of test for floating_

STF_CASE ( "ne bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ne;

  using r_t = decltype(ne(bool(), bool()));

  // return type conformity test
  STF_TYPE_IS(r_t, bool);


  // specific values tests
  STF_EQUAL(ne(true, false), true);
  STF_EQUAL(ne(false, true), true);
  STF_EQUAL(ne(true, true), false);
  STF_EQUAL(ne(false, false), false);
}




