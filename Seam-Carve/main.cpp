#include "Blur.h"
#include "graphics.h"
#include "SeamCarving.h"

void render() {
    SeamCarving::render();
}


void blurImage() {
    auto *imageObject = new ImageObject("paw.ppm");
    Blur blur(imageObject);
    //blur.buildMegaNode();
    blur.calculateBlur();
    imageObject->writeImage("paw2.ppm");
}

void seamCarvingSetup(int argc, char *argv[]) {
    auto *imageObject = new ImageObject("billboard.ppm");
    auto *blur = new Blur(imageObject);
    blur->calculateBlur();
    SeamCarving seamCarving(imageObject,blur);
    init_graphics(argc, argv, imageObject->getWidth(), imageObject->getHeight(),
                  render, SeamCarving::keyhandler, SeamCarving::timer);
}

int main(int argc, char *argv[]) {
    seamCarvingSetup(argc, argv);
}





