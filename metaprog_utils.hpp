#ifndef __CPP_PACKED_TUPLE_METAPROG_UTILS_HPP__
#define __CPP_PACKED_TUPLE_METAPROG_UTILS_HPP__

namespace metaprog {

template <typename T, size_t N, size_t I = N>
constexpr T Accumulate(std::array<T, N> const& container)
{
  if constexpr (I == 0) {
    return std::get<I>(container);
  }
  return std::get<I>(container) + Accumulate<T, N, I - 1>(container);
}

template <typename ...T>
constexpr size_t  SizeOf()
{
  std::array<size_t, sizeof...(T)> sizes = { sizeof(T)... };

  return Accumulate<size_t, sizeof...(T)>(sizes, 0);
}

} // end of namespace metaprog

#endif // __CPP_PACKED_TUPLE_METAPROG_UTILS_HPP__
