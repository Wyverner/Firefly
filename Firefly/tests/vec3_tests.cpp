// vec3_tests.cpp
// 11/22/25

#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#define FIREFLY_RUNNING_TESTS

#include "../src/vec3.hpp" // include this before doctest
#include "../tests/doctest.h" 

TEST_CASE("vec3 is default-constructible and zero-initialized") {
   constexpr vec3 v;
   CHECK(vec3_test_accessor::x(v) == 0.0);
   CHECK(vec3_test_accessor::y(v) == 0.0);
   CHECK(vec3_test_accessor::z(v) == 0.0);
   }

TEST_CASE("vec3 constructed and initialized") {
   constexpr vec3 v{ 1, 4, 7 };
   CHECK(vec3_test_accessor::x(v) == 1.0);
   CHECK(vec3_test_accessor::y(v) == 4.0);
   CHECK(vec3_test_accessor::z(v) == 7.0);
   }

TEST_CASE("vec3 rgb accessors") {
   constexpr vec3 v{ 1, 4, 7 };
   CHECK(v.r() == 1.0);
   CHECK(v.g() == 4.0);
   CHECK(v.b() == 7.0);
   }

TEST_CASE("vec3 basic arithmetic - constexpr") {
   constexpr vec3 a{1, 2, 3};
   constexpr vec3 b{4, 5, 6};

   constexpr vec3 sum  = a + b;
   constexpr vec3 diff = a - b;
   constexpr vec3 scaled = a * 2.0;
   constexpr vec3 rescaled = scaled / 2.0;
   constexpr vec3 lerp_result = lerp(0.5, a, b);

   CHECK(sum  == vec3{5,  7,  9});
   CHECK(diff == vec3{-3, -3, -3});
   CHECK(scaled == vec3{2, 4, 6});
   CHECK(rescaled == a);
   CHECK(lerp_result == vec3{2.5, 3.5, 4.5});
   }

TEST_CASE("vec3 equality")
   {
   constexpr vec3 a{ 1, 2, 3 };
   constexpr vec3 b{ 4, 5, 6 };
   constexpr vec3 c{ 5, 7, 9 };
   CHECK((a + b) == c);
   CHECK(a != c);
   }

TEST_CASE("vec3 assignment operators")
   {
   constexpr vec3 a{ 1, 2, 3 };
   constexpr vec3 b{ 4, 5, 6 };
   constexpr vec3 c{ 5, 7, 9 };
   constexpr vec3 d{ 8, 10, 12 };

   vec3 add = a; add += b;   CHECK(add == c);
   vec3 sub = c; sub -= b;   CHECK(sub == a);
   vec3 mul = b; mul *= 2.0; CHECK(mul == d);
   vec3 div = d; div /= 2.0; CHECK(div == b);
   }

TEST_CASE("vec3 unary operator(s)")
   {
   constexpr vec3 a{ 1, 2, 3 };
   CHECK(-a == vec3(-1, -2, -3));
   }

TEST_CASE("dot, cross, length_squared - constexpr") {
   constexpr vec3 a{1, 2, 3};
   constexpr vec3 b{4, 5, 6};

   CHECK(a.dot(b) == 32.0);
   CHECK(a.cross(b) == vec3{-3, 6, -3});
   CHECK(a.length_squared() == 14.0);
   CHECK(b.length_squared() == 77.0);
   }

TEST_CASE("vec3 friend scaling")
   {
   constexpr vec3 a{1, 2, 3};
   CHECK((2.0 * a) == (a * 2.0));
   }

TEST_CASE("normalized vectors - runtime") {
   vec3 v{3, 4, 0};
   vec3 n = v.normalized();
   CHECK(n.length() == doctest::Approx(1.0).epsilon(0.00001));
   }