#ifndef CTIMEIT_H
#define CTIMEIT_H

#include <chrono>
#include <cmath>
#include <iostream>
#include <limits>

namespace ctimeit {
using GetTime = std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
std::string format_time(int64_t);

template <size_t N = 1000, typename Callable, typename... Args>
void timeit(Callable func, Args&&... Funcargs) {
  /*
   * Measure the average execution time of `func` which takes `Funcargs`
   * after `N` executions.
   */

  double total_time{0};
  int64_t min_exec_time{std::numeric_limits<int64_t>::max()}, max_exec_time{0};

  for (size_t i = 0; i < N; ++i) {
    auto start = GetTime::now();
    func(std::forward<Args>(Funcargs)...);
    auto end = GetTime::now();

    auto run_time =
        duration_cast<std::chrono::nanoseconds>(end - start).count();
    min_exec_time = std::min(min_exec_time, run_time);
    max_exec_time = std::max(max_exec_time, run_time);
    total_time += run_time;
  }

  std::cout << "Average time taken : " << format_time(total_time / N) << " ("
            << N << " runs)\n"
            << "Max time taken     : " << format_time(max_exec_time) << "\n"
            << "Min time taken     : " << format_time(min_exec_time) << "\n";
}

std::string format_time(int64_t run_time) {
  /*
   * For setting the scale of execution time.
   */

  std::string formats[]{"ns", "µs", "ms", "s"};
  float scaling[]{1, 1e3, 1e6, 1e9};
  int pow = std::floor(std::log10(run_time));
  int idx = std::max(0, pow / 3);
  return std::to_string(run_time / scaling[idx]) + formats[idx];
}

}  // namespace ctimeit

#endif  // CTIMEIT_H
