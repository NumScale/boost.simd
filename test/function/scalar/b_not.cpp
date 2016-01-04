//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/b_not.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <nontrivial.hpp>


STF_CASE_TPL ("check b_not for floating",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::b_not;
  using bs::tag::b_not_;
  using r_t = decltype(b_not(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(b_not(bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_IEEE_EQUAL(b_not(bs::Zero<T>()), bs::Nan<r_t>());
} // end of test for floating_

STF_CASE_TPL ("check b_not for integral",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::b_not;
  using bs::tag::b_not_;
  using r_t = decltype(b_not(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(b_not(bs::One<T>()), bs::shift_left(bs::Mone<r_t>(),1));
  STF_EQUAL(b_not(bs::Three<T>()), bs::shift_left(bs::Mone<r_t>(),2));
  STF_EQUAL(b_not(bs::Zero<T>()), bs::Mone<r_t>());
} // end of test for integer_

namespace foo
{
  template <class T>
  nontrivial<T> operator ~(const nontrivial<T> & z1)
  {
    return perform(z1);
  }
}
