// Firefly Ray Tracer
// dob - 11/21/25
// kudos to Grok & Jamis Buck

#include <iostream>
#include "vec3.hpp"
#include <fstream>
#include <string>
#include <format>

int main()
   {
   std::cout << "Firefly Ray Tracer - \"You can't take the sky from me.\"\n";
   std::cout << "ver 0.0.0.2\n\n";

   std::string filename{ "test.ppm" };
   std::ofstream fout(filename);

   const int width  = 256;
   const int height = 256;

   fout << std::format("P3\n{} {}\n255\n", width, height);

   for (int j = height-1; j >= 0; --j) {
      for (int i = 0; i < width; ++i) {
         color pixel = lerp(
            static_cast<double>(j) / (height-1),   // t from 1 (top) → 0 (bottom)
            color{0.2, 0.4, 0.8},                  // top = sky blue
            color{1.0, 0.9, 0.7}                   // bottom = warm sunset
         );

         int r = static_cast<int>(255.999 * pixel.r());
         int g = static_cast<int>(255.999 * pixel.g());
         int b = static_cast<int>(255.999 * pixel.b());

         fout << std::format("{} {} {}\n", r, g, b);
         }
      }

   fout.close();

   return 0;
   }