//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/is_normal.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/constant/quarter.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" is_normal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_normal;

  using r_t = decltype(is_normal(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(is_normal(bs::Inf<T>()), r_t(false));
  STF_EQUAL(is_normal(bs::Minf<T>()), r_t(false));
  STF_EQUAL(is_normal(bs::Nan<T>()), r_t(false));
#endif
  STF_EQUAL(is_normal(-bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_normal(bs::Half<T>()), r_t(true));
  STF_EQUAL(is_normal(bs::Mone<T>()), r_t(true));
  STF_EQUAL(is_normal(bs::One<T>()), r_t(true));
  STF_EQUAL(is_normal(bs::Quarter<T>()), r_t(true));
  STF_EQUAL(is_normal(bs::Two<T>()), r_t(true));
  STF_EQUAL(is_normal(bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_normal(bs::Smallestposval<T>()),  r_t(true));
#ifndef STF_NO_NORMAL
  STF_EQUAL(is_normal(bs::Mindenormal<T>()), r_t(false));
  STF_EQUAL(is_normal(bs::Smallestposval<T>()/bs::Two<T>()), r_t(false));
#endif
}

STF_CASE_TPL (" is_normal signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_normal;
  using r_t = decltype(is_normal(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_normal(bs::Mone<T>()), r_t(true));
  STF_EQUAL(is_normal(bs::One<T>()), r_t(true));
  STF_EQUAL(is_normal(bs::Two<T>()), r_t(true));
  STF_EQUAL(is_normal(bs::Zero<T>()), r_t(true));
}

STF_CASE_TPL (" is_normal unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_normal;

  using r_t = decltype(is_normal(T()));
  typedef bs::logical<T> wished_r_t;

  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(is_normal(bs::One<T>()), r_t(true));
  STF_EQUAL(is_normal(bs::Two<T>()), r_t(true));
  STF_EQUAL(is_normal(bs::Zero<T>()), r_t(true));
}

STF_CASE ( "is_normal bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_normal;
  using r_t = decltype(is_normal(bool()));

  // return type conformity test
  STF_TYPE_IS(r_t, bool);

  // specific values tests
  STF_EQUAL(is_normal(true), true);
  STF_EQUAL(is_normal(true), true);
}


STF_CASE_TPL (" is_normal std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_normal;

  using r_t = decltype(is_normal(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(is_normal(bs::Inf<T>(), bs::std_), r_t(false));
  STF_EQUAL(is_normal(bs::Minf<T>(), bs::std_), r_t(false));
  STF_EQUAL(is_normal(bs::Nan<T>(), bs::std_), r_t(false));
#endif
  STF_EQUAL(is_normal(-bs::Zero<T>(), bs::std_), r_t(false));
  STF_EQUAL(is_normal(bs::Half<T>(), bs::std_), r_t(true));
  STF_EQUAL(is_normal(bs::Mone<T>(), bs::std_), r_t(true));
  STF_EQUAL(is_normal(bs::One<T>(), bs::std_), r_t(true));
  STF_EQUAL(is_normal(bs::Quarter<T>(), bs::std_), r_t(true));
  STF_EQUAL(is_normal(bs::Two<T>(), bs::std_), r_t(true));
  STF_EQUAL(is_normal(bs::Zero<T>(), bs::std_), r_t(false));
  STF_EQUAL(is_normal(bs::Smallestposval<T>(), bs::std_),  r_t(true));
#ifndef STF_NO_NORMAL
  STF_EQUAL(is_normal(bs::Mindenormal<T>(), bs::std_), r_t(false));
  STF_EQUAL(is_normal(bs::Smallestposval<T>()/bs::Two<T>(), bs::std_), r_t(false));
#endif
}
