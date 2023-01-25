//
// Created by Gavin Taylor Mcroy on 12/1/20.
//

#include <cstdio>
#include "ImageObject.h"

ImageObject::Pixel::Pixel() {
    r = 0;
    g = 0;
    b = 0;
}

ImageObject::ImageObject(const char *filename) {
    readImage(filename);
}

ImageObject::Pixel &ImageObject::getPixel(int x, int y) {
    return image[y * width + x];
}

void ImageObject::writeImage(const char *filename) {
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(image, width * height, sizeof(Pixel), fp);
    fclose(fp);
}

void ImageObject::readImage(const char *filename) {
    FILE *fp = fopen(filename, "r");
    int dummy = fscanf(fp, "P6\n%d %d\n255%*c", &width, &height);
    image = new Pixel[width * height];
    dummy = fread(image, width * height, sizeof(Pixel), fp);
}

void ImageObject::carveImage() {
    Pixel *orig_image = image;
    width--;
    image = new Pixel[height * width];
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            getPixel(x, y) = orig_image[y * (width + 1) + x];
    delete[] orig_image;
}

bool ImageObject::Pixel::operator<(const ImageObject::Pixel &pixel) const {
    return (r + g + b) > (pixel.r + pixel.g + pixel.b);
}

bool ImageObject::Pixel::operator!=(const ImageObject::Pixel &pixel) const {
    return (r != pixel.r && g != pixel.g && b != pixel.b);
}

bool ImageObject::Pixel::operator==(const ImageObject::Pixel &pixel) const {
    return (r == pixel.r && g == pixel.g && b == pixel.b);
}
