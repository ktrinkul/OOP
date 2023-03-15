#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include <C:\Users\mgory\vcpkg\buildtrees\doctest\src\v2.4.9-a2b8cf4cf7.clean\doctest\doctest.h>
//#include <C:\Users\mgory\OneDrive\Рабочий стол\univer\2_sem\OOP\goryacheva_e_m\prj.lab\rational\include\rational\rational.hpp>

#include <doctest/doctest.h>
#include <rational/rational.hpp>

TEST_CASE("[rational] - Rational ctor") {
  CHECK(Rational() == Rational(0, 1));
  CHECK(Rational(3) == Rational(3, 1));
  CHECK(Rational(-3) == Rational(-3, 1));
  CHECK(Rational(10, 6) == Rational(5, 3));
  CHECK(Rational(-10, 6) == Rational(-5, 3));
  CHECK(Rational(10, -6) == Rational(-5, 3));
  CHECK(Rational(-10, -6) == Rational(5, 3));
  CHECK_THROWS(Rational(1, 0));
}
