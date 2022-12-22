#include <iostream>
#include <OpenImageIO/imageio.h>
#include <vector>

using namespace OIIO;

/* input morph, output morph, txt with directed line segments */
int main(int args, char *argv[]) {
    std::string filename = "input.jpeg";
    auto input = ImageInput::open(filename);

    if (!input) {
        std::cerr << "Error loading image" << std::endl;
        exit(1);
    }
    const ImageSpec &spec = input->spec();
    int xRes = spec.width;
    int yRes = spec.height;
    int channels = spec.nchannels;
    std::vector<unsigned char> pixels(xRes * yRes * channels);

    input->read_image(TypeDesc::UINT8, &pixels[0]);
    input->close();


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
