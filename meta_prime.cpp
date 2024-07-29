/**
 * Taken from section 23.7 of "C++ Templates" (2nd ed.)
 *
 * Which is based on:
 *   http://www.erwin-unruh.de/primorig.html
 *
 * The gist: compute prime numbers at compile time via compile errors
 */

/*
MSVC compiler will stop at first error, clang will show all.

(clang-tidy errors at line 59, with LAST = 32)

  No viable conversion from 'const int' to 'D<2>'
  No viable conversion from 'const int' to 'D<3>'
  No viable conversion from 'const int' to 'D<5>'
  No viable conversion from 'const int' to 'D<7>'
  No viable conversion from 'const int' to 'D<11>'
  No viable conversion from 'const int' to 'D<13>'
  No viable conversion from 'const int' to 'D<17>'
  No viable conversion from 'const int' to 'D<19>'
  No viable conversion from 'const int' to 'D<23>'
  No viable conversion from 'const int' to 'D<29>'
  No viable conversion from 'const int' to 'D<31>'

*/

template<int P, int I>
struct is_prime {
  enum { pri = (P == 2) || ((P % I) && is_prime<(I > 2 ? P : 0), I - 1>::pri) };
};

template<>
struct is_prime<0, 0> {
  enum { pri = 1 };
};

template<>
struct is_prime<0, 1> {
  enum { pri = 1 };
};

template<int I>
struct D {
  D(void*);
};

template<int I>
struct CondNull {
  static int const value = I;
};

template<>
struct CondNull<0> {
  inline static void* value = nullptr;
};

template<int I>
struct prime_print {
  prime_print<I - 1> a;

  enum { pri = is_prime<I, I - 1>::pri };

  void f() {
    D<I> d = CondNull < pri ? 1 : 0 > ::value;
    a.f();
  }
};

template<>
struct prime_print<1> {
  enum { pri = 0 };

  void f() { D<1> d = 0; }
};

#ifndef LAST
#define LAST 32
#endif

int main() {
  prime_print<LAST> a;
  a.f();
}