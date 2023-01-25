//
// Created by Gavin Taylor Mcroy on 12/1/20.
//

#ifndef PROJECT_4_CLION_IMAGEOBJECT_H
#define PROJECT_4_CLION_IMAGEOBJECT_H


class ImageObject {
public:
    struct Pixel {
        unsigned char r, g, b;

        bool operator<(const Pixel &pixel) const;

        bool operator!=(const Pixel &pixel) const;

        bool operator==(const Pixel &pixel) const;

        Pixel(unsigned char r, unsigned char g, unsigned char b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }

        Pixel();
    };

    Pixel * image;

     Pixel white = {255, 255, 255};
     Pixel black = {0, 0, 0};
     Pixel red = {255, 0 , 0};

    explicit ImageObject(const char *filename);

    Pixel & getPixel(int x, int y);

    void writeImage(const char *filename);

    void carveImage();

    int getWidth() const{ return width; }

    int getHeight() const { return height; }


private:
    int width;
    int height;

    void readImage(const char *filename);

};


#endif //PROJECT_4_CLION_IMAGEOBJECT_H
