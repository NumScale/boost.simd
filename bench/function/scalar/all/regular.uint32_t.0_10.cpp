// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor all in scalar mode for std::uint32_t type with no decorator (regular call).
#include <scalar_bench.hpp>
#include <boost/scalar/function/all.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::scalar;

DEFINE_SCALAR_BENCH(scalar_all, bs::all);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_all, std::uint32_t>(0, 10);
}
