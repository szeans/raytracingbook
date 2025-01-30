#include "color.h"
#include "vec3.h"

#include <iostream>

using namespace std;

int main() {
  // image

  int image_width = 256;
  int image_height = 256;

  // render

  cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int i = 0; i < image_height; i++) {
    clog << "/rScanlines remaining: " << (image_height - i) << ' ' << flush;
    for (int j = 0; j < image_width; j++) {
      auto pixel_color = color(double(i) / (image_width - 1),
                               double(j) / (image_height - 1), 0.0);

      write_color(cout, pixel_color);
    }
  }

  clog << "\rDone.              \n";
}
