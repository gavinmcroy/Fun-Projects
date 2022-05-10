#include <iostream>
#include <fstream>

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
            auto r = double(i) / (IMAGE_WIDTH - 1);
            auto g = double(j) / (IMAGE_HEIGHT - 1);
            auto b = .25;

            int ir = static_cast<int>(256.999 * r);
            int ig = static_cast<int>(256.999 * g);
            int ib = static_cast<int>(256.999 * b);

            file << ir << " " << ig << " " << ib << std::endl;
        }
    }

    file.close();

    return 0;
}
