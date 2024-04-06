#include <algorithm>
#include <cmath>
#include <fstream>

#include "Vec.h"
#include "Ray.h"
#include "Sphere.h"
#include "Color.h"
#include "lodepng.h"

constexpr Color Color::BLACK = { 0x00, 0x00, 0x00 };
constexpr Color Color::WHITE = { 0xff, 0xff, 0xff };
constexpr Color Color::RED   = { 0xff, 0x00, 0x00 };

constexpr const char *FILE_NAME = "output.png";
constexpr unsigned WIDTH = 640;
constexpr unsigned HEIGHT = 480;

int main() {
    std::vector<unsigned char> image(WIDTH * HEIGHT * 4, 255); // RGBA image buffer

    const Color& white = Color::WHITE;
    const Color& red = Color::RED;

    const Sphere sphere(Vec(WIDTH / 2, HEIGHT / 2, 50), 150);
    const Sphere light(Vec(WIDTH, HEIGHT / 2, 0), 1);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Send a ray through each pixel
            const Ray ray(Vec(x, y, 0), Vec(0, 0, 1));

            double t = 0;

            Color pixel = Color::BLACK;

            // Check for intersections
            if (sphere.intersect(ray, t)) {
                // Point of intersection
                const Vec& pi = ray.o + ray.d * t;

                // Color the pixel
                const Vec& L = light.c - pi;
                const Vec& N = sphere.getNormal(pi);

                double const dt = L.normalize().dot(N.normalize());

                pixel = red + (white * dt) * 1.0;
                pixel.cap();
            }

            // Convert Color to RGBA format and store in the image buffer
            const int pixelIndex = (y * WIDTH + x) * 4;
            image[pixelIndex + 0] = pixel.r;
            image[pixelIndex + 1] = pixel.g;
            image[pixelIndex + 2] = pixel.b;
            image[pixelIndex + 3] = 255; // Alpha channel

        }
    }

    // Save the image as PNG
    lodepng::encode(FILE_NAME, image, WIDTH, HEIGHT);

    return 0;
}