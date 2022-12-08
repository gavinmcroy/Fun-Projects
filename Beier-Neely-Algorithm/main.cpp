#include <iostream>
#include <OpenImageIO/imageio.h>

using namespace OIIO;
using namespace OpenImageIO_v2_4;

/* input morph, output morph, txt with directed line segments */
int main(int args, char * argv[]) {
    std::string filename = "file.png";
    std::string file2;

    /* Load morph1 into memory */
    auto input = ImageInput::open(filename);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
