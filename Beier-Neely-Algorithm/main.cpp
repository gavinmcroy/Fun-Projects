#include <iostream>
#include <OpenImageIO/imageio.h>
#include <vector>

using namespace OIIO;

/* input morph, output morph, txt with directed line segments */
int main(int args, char *argv[]) {
    std::string filename = "input.jpeg";
    std::string outputName = "test.jpeg";
    auto input = ImageInput::open(filename);

    if (!input) {
        std::cerr << "Error loading image" << std::endl;
        exit(1);
    }
    const ImageSpec &spec = input->spec();
    const int xRes = spec.width;
    const int yRes = spec.height;
    const int channels = spec.nchannels;
    std::vector<unsigned char> pixels(xRes * yRes * channels);

    input->read_image(TypeDesc::UINT8, &pixels[0]);
    input->close();

    auto out = ImageOutput::create(outputName);
    if (!out) {
        std::cerr << "Error generating output image " << std::endl;
        exit(1);
    }
   
    out->open(outputName, spec);
    out->write_image(TypeDesc::UINT8, &pixels[0]);
    out->close();

    return 0;
}
