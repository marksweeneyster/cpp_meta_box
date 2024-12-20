#include <array>
#include <cassert>
#include <format>
#include <iostream>

template<typename T, std::size_t N>
constexpr T DotProduct(const std::array<T, N>& a, const std::array<T, N>& b) {
  T result{};
  for (std::size_t ii = 0; ii < N; ++ii) {
    result += a[ii] * b[ii];
  }
  return result;
}

template<typename T, std::size_t N>
struct DotProductT {
  static inline constexpr T result(const T* a, const T* b) {
    return *a * *b + DotProductT<T,N-1>::result(a+1,b+1);
  }
};

template<typename T>
struct DotProductT<T, 0> {
  static inline constexpr T result(const T* a, const T* b) {
    return T{};
  }
};

template<typename T, std::size_t N>
constexpr T DotProductR(const std::array<T, N>& a, const std::array<T, N>& b) {
  return DotProductT<T,N>::result(&a[0], &b[0]);
}

int main() {
  constexpr std::array<int, 11> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  constexpr std::array<int, 11> b = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  static_assert(DotProduct(a, b) == 165, "do the math");
  static_assert(DotProductR(a, b) == 165, "do the math");

  std::array<double, 2> sides = {3., 4.};

  auto hyp_sq = DotProduct(sides, sides);
  std::cout << std::format("3-4-5? {}\n", hyp_sq);
  auto hyp_sq_r = DotProductR(sides, sides);

  assert(hyp_sq == hyp_sq_r);
}