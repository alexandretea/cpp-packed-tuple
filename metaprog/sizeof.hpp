#ifndef __CPP_PACKED_TUPLE_METAPROG_SIZEOF_HPP__
#define __CPP_PACKED_TUPLE_METAPROG_SIZEOF_HPP__

#include <array>
#include <tuple>
#include "accumulate.hpp"

namespace metaprog {

// Just an alias for an std::array built from packed parameters
template <typename ...T>
using SizeArray = std::array<size_t, sizeof...(T)>;

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

template <typename ...T>
constexpr SizeArray<T...> SizeOfEach()
{
  return SizeArray<T...> { sizeof(T)... };
}

template <typename ...T>
constexpr size_t  SizeOf()
{
  return Accumulate<size_t, sizeof...(T)>(SizeOfEach<T...>());
}

} // end of namespace metaprog

#endif // __CPP_PACKED_TUPLE_METAPROG_SIZEOF_HPP__

