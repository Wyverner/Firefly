#pragma once

// vec3.hpp - 11/21/25

#include <cmath>
#include <format>
#include <ostream>
#include <string>

class vec3
   {
   private:
      double x{};
      double y{};
      double z{};

#ifdef FIREFLY_RUNNING_TESTS
   friend class vec3_test_accessor;
#endif

   public:
      constexpr vec3() noexcept = default;
      constexpr vec3(double x, double y, double z) noexcept : x(x), y(y), z(z)
         {}

      // Component Access

      [[nodiscard]] constexpr double r() const noexcept { return x; }
      [[nodiscard]] constexpr double g() const noexcept { return y; }
      [[nodiscard]] constexpr double b() const noexcept { return z; }

      // Operations

      [[nodiscard]] constexpr vec3 operator+ (const vec3& v) const noexcept
         {
         return vec3(x + v.x, y + v.y, z + v.z);
         }

      [[nodiscard]] constexpr vec3 operator- (const vec3& v) const noexcept
         {
         return vec3(x - v.x, y - v.y, z - v.z);
         }

      [[nodiscard]] constexpr vec3 operator* (double scale) const noexcept
         {
         return vec3(x * scale, y * scale, z * scale);
         }

      [[nodiscard]] constexpr vec3 operator/ (double scale) const noexcept
         {
         return vec3(x / scale, y / scale, z / scale);
         }

      [[nodiscard]] constexpr bool operator== (const vec3& v) const noexcept
         {
         return (x == v.x) && (y == v.y) && (z == v.z);
         }

      [[nodiscard]] constexpr bool operator!= (const vec3& v) const noexcept
         {
         return !(*this == v);
         }

      constexpr vec3& operator+= (const vec3& v) noexcept
         {
         x += v.x;
         y += v.y;
         z += v.z;
         return *this;
         }

      constexpr vec3& operator-= (const vec3& v) noexcept
         {
         x -= v.x;
         y -= v.y;
         z -= v.z;
         return *this;
         }

      constexpr vec3& operator*= (double scale) noexcept
         {
         x *= scale;
         y *= scale;
         z *= scale;
         return *this;
         }

      constexpr vec3& operator/= (double scale) noexcept
         {
         x /= scale;
         y /= scale;
         z /= scale;
         return *this;
         }

      [[nodiscard]] constexpr vec3 operator- () const noexcept
         {
         return vec3(-x, -y, -z);
         }

      // Functions

      [[nodiscard]] constexpr double length_squared() const noexcept
         {
         return x*x + y*y + z*z;
         }

      [[nodiscard]] constexpr double dot(const vec3& v) const noexcept
         {
         return x * v.x + y * v.y + z * v.z;
         }

      [[nodiscard]] constexpr vec3 cross(const vec3& v) const noexcept
         {
         return vec3(y * v.z - z * v.y,
                     z * v.x - x * v.z,
                     x * v.y - y * v.x);
         }

      [[nodiscard]] std::string toString() const noexcept
         {
         return std::format("vec3 [{}, {}, {}]", x, y, z);
         }

      //--------------------
      // These are NOT constexpr, they depend on std::sqrt
      //--------------------

      [[nodiscard]] double length() const noexcept // note : not constexpr
         {
         return std::sqrt(length_squared());
         }

      [[nodiscard]] vec3 normalized() const noexcept // note : not constexpr
         {
         return *this / length();
         }

      // Friends

      friend std::ostream& operator<< (std::ostream& os, const vec3& v) noexcept
         {
         return
            os << "vec3  ["
            << v.x << ", "
            << v.y << ", "
            << v.z << "]";
         }
      
      [[nodiscard]] friend constexpr vec3 operator* (double scale, const vec3& v) noexcept
         {
         return v * scale;
         }

      [[nodiscard]] friend constexpr vec3 lerp(double t, const vec3& a,
                                               const vec3& b) noexcept
         {
         return (1.0 - t)*a + t*b;
         }
   }; 

#ifdef FIREFLY_RUNNING_TESTS
   class vec3_test_accessor
      {
      public:
         static constexpr double x(const vec3& v) noexcept { return v.x; }
         static constexpr double y(const vec3& v) noexcept { return v.y; }
         static constexpr double z(const vec3& v) noexcept { return v.z; }
      };
#endif

using color = vec3;
using point3 = vec3;