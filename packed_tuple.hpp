#ifndef __CPP_PACKED_TUPLE_PACKED_TUPLE_HPP__
#define __CPP_PACKED_TUPLE_PACKED_TUPLE_HPP__

#include <memory>
#include <vector>
#include <numeric>

// TODO only primitive types
template <typename ...ContentTypes>
class PackedTuple
{
  public:
    PackedTuple()
      : total_size_(SizeOf<ContentTypes...>()), raw_data_(0)
    {}

  private:
    const size_t                        total_size_;
    std::array<uint8_t, SizeOf<ContentTypes...>()> raw_data_;
    // TODO alias
};

#endif // __CPP_PACKED_TUPLE_PACKED_TUPLE_HPP__
