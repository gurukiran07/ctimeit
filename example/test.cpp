#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>

#include "ctimeit.h"

using namespace ctimeit;

int64_t Sum(std::vector<int> vec) {
  int64_t sum = 0;
  for (auto i : vec) {
    sum += i;
  }
  return sum;
}

void anotherFunc(int x, int y, float z) {
  while (x--) {
  }
}

int64_t SomeFunc(std::vector<int> vec) {
  int64_t sum = 0;
  for (auto i : vec) sum += i;
  return sum;
}

int64_t SomeFuncByRef(std::vector<int>& vec) {
  int64_t sum = 0;
  for (auto i : vec) sum += i;
  return sum;
}

int main() {
  std::srand(unsigned(std::time(nullptr)));
  std::vector<int> v(100000);
  std::generate(v.begin(), v.end(), std::rand);

  std::cout << "-------SomeFunc---------\n";
  timeit(SomeFunc, v);
  std::cout << "-------anotherFunc with N arg---------\n";
  timeit<100>(anotherFunc, 10, 20, 40.f);
  std::cout << "-------SomeFuncByRef with N arg---------\n";
  timeit<1000>(SomeFuncByRef, v);
}
