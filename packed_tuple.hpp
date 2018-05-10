#ifndef __CPP_PACKED_TUPLE_PACKED_TUPLE_HPP__
#define __CPP_PACKED_TUPLE_PACKED_TUPLE_HPP__

#include <memory>
#include <array>
#include <numeric>
#include "metaprog_utils.hpp"

// TODO only primitive types
template <typename ...ContentTypes>
class PackedTuple
{
  public:
    static constexpr size_t kByteSize = metaprog::SizeOf<ContentTypes...>();

    PackedTuple()
      : raw_data_()
    {}

  private:
    std::array<uint8_t, kByteSize> raw_data_;
};

#endif // __CPP_PACKED_TUPLE_PACKED_TUPLE_HPP__
