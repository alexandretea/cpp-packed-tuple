#ifndef __CPP_PACKED_TUPLE_METAPROG_ACCUMULATE_HPP__
#define __CPP_PACKED_TUPLE_METAPROG_ACCUMULATE_HPP__

#include <array>

namespace metaprog {

template <typename T, size_t N, size_t I = N - 1>
constexpr T Accumulate(std::array<T, N> const& container)
{
  if constexpr (I == 0) {
    return std::get<I>(container);

  } else {
    // Note: The else-condition is required to explicitly tell the compiler to
    // not reach the following line if the above if-condition matches. Otherwise
    // an out-of-bound compile error is raised.
    return std::get<I>(container) + Accumulate<T, N, I - 1>(container);
  }
}
} // end of namespace metaprog

#endif // __CPP_PACKED_TUPLE_METAPROG_ACCUMULATE_HPP__


