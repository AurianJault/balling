#ifndef COLOR_H
#define COLOR_H

#include "interval.h"
#include "vec3.h"


using color = vec3;

void write_color(std::ostream &out, const color& pixel_color)
{
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  

  static const interval intensity(0.000, 0.999);
  
  int rByte = int(256 * intensity.clamp(r));
  int gByte = int(256 * intensity.clamp(g));
  int bByte = int(256 * intensity.clamp(b)); 

  out << rByte << ' ' << gByte << ' ' << bByte << "\n";
};


#endif
