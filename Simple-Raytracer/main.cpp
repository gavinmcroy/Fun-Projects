#include <iostream>
#include <fstream>

#include "vec3.h"
#include "color.h"

int main() {

    const int IMAGE_HEIGHT = 256;
    const int IMAGE_WIDTH = 256;

    std::fstream file;
    file.open("file.ppm", std::ios::out);
    if (!file) {
        std::cerr << "error" << std::endl;
    }

    file << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n" << "255\n";

    for (int j = IMAGE_HEIGHT - 1; j >= 0; j--) {
        std::cout << "\rScan lines Remaining:" << j << " " << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; i++) {
            color pixel_color(double(i) / (IMAGE_WIDTH - 1), double(j) / (IMAGE_HEIGHT - 1), .25);
            write_color(file, pixel_color);
        }
    }

    file.close();

    return 0;
}
