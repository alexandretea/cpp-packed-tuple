#include <iostream>
#include "packed_tuple.hpp"

int main()
{
  PackedTuple<int, char, uint64_t, char>  test(1, 'p', 99, 'o');

  std::cout << test.Get<0>() << std::endl;
  std::cout << test.Get<1>() << std::endl;
  std::cout << test.Get<2>() << std::endl;
  std::cout << test.Get<3>() << std::endl;

  std::cout << std::endl;

  test.Get<0>() = 42;
  test.Get<1>() = 'c';
  test.Get<2>() = 81;
  test.Get<3>() = 'a';

  std::cout << test.Get<0>() << std::endl;
  std::cout << test.Get<1>() << std::endl;
  std::cout << test.Get<2>() << std::endl;
  std::cout << test.Get<3>() << std::endl;
  return 0;
}

