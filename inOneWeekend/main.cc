#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

using namespace std;

color ray_color(const ray &r) {
  vec3 unit_direction = unit_vector(r.direction());
  auto a = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main() {
  // image

  auto aspect_ratio = 16.0 / 9.0;

  int image_width = 400;

  int image_height = int(image_width / aspect_ratio);
  image_height = (image_height > 1) ? (image_height) : (1);

  // camera

  // dist from viewport and camera center
  auto focal_length = 1.0;
  auto camera_center = point3(0, 0, 0);

  auto viewport_height = 2.0;
  auto viewport_width = viewport_height * (double(image_width) / image_height);

  // viewport vectors
  auto viewport_u = vec3(viewport_width, 0, 0);
  auto viewport_v = vec3(0, -viewport_height, 0);

  // delta vectors from pixel to pixel
  auto pixel_delta_u = viewport_u / image_width;
  auto pixel_delta_v = viewport_v / image_height;

  // upper left pixel location
  auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) -
                             viewport_u / 2 - viewport_v / 2;
  auto pixel00_loc =
      viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

  // render

  cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    clog << "\rScanlines remaining: " << (image_height - j) << ' ' << flush;
    for (int i = 0; i < image_width; i++) {
      auto pixel_center =
          pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
      auto ray_direction = pixel_center - camera_center;
      ray r(camera_center, ray_direction);

      color pixel_color = ray_color(r);

      write_color(cout, pixel_color);
    }
  }

  clog << "\rDone.              \n";
}
