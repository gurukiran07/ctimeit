# ctimeit
Basic benchmarking utility in c++ for measuring run time of your function. For proper benchmarking refer to [Google/benchmark](https://github.com/google/benchmark).

## Usage

```cpp
ctimeit::timeit(func_name, func_arg1, func_args2, ...);
```

## Example

```cpp
#include <iostream>
#include <vector>
#include "ctimeit.h"

using namespace ctimeit;

void anotherFunc(int x, int y, float z){

  while(x--){
		
  }
}

int64_t SomeFunc(std::vector<int> vec){
  int64_t sum = 0;
  for(auto i: vec)sum+=i;
  return sum;
}

int main(){
  std::srand(unsigned(std::time(nullptr)));
  std::vector<int> v(100000);
  std::generate(v.begin(), v.end(), std::rand);

  std::cout<<"-------SomeFunc---------\n";
  timeit(SomeFunc, v); //default N i.e 1000
  std::cout<<"-------anotherFunc with N arg---------\n";
  timeit<100>(anotherFunc, 10, 20, 40.f);
  std::cout<<"-------SomeFunc with N arg---------\n";
  timeit<1000>(SomeFunc, v);
}
```
### Output to console

```
-------SomeFunc---------
Average time taken : 904.073975µs (1000 runs)
Max time taken     : 4.574131ms
Min time taken     : 834.716003µs
-------anotherFunc with N arg---------
Average time taken : 45.000000ns (100 runs)
Max time taken     : 137.000000ns
Min time taken     : 39.000000ns
-------SomeFunc with N arg---------
Average time taken : 883.750000µs (1000 runs)
Max time taken     : 1.740087ms
Min time taken     : 833.549011µs
```

### Requirements

- C++11 or above.
