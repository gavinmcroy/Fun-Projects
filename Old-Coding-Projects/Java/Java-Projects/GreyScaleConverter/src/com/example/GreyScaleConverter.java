package com.example;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class GreyScaleConverter {

    private BufferedImage image = null;

    public GreyScaleConverter() {
        loadFile();
        processImage(image);
        writeImage(image);
    }

    private void loadFile() {
        try {
            File file = new File("D://Image/800.jpg");
            image = ImageIO.read(file);
            System.out.println("File read");
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    private void processImage(BufferedImage image) {
        for (int y = 0; y < image.getHeight(); y++) {
            for (int x = 0; x < image.getWidth(); x++) {
                int pixel = image.getRGB(x, y);
                int red = (pixel >> 16) & 0xff;
                int green = (pixel >> 8) & 0xff;
                int blue = pixel & 0xff;
                int average = (red + green + blue) / 3;
                int alpha = 255;
                red = average;
                green = average;
                blue = average;
                pixel = (alpha << 24) | (red << 16) | (green << 8) | blue;
                image.setRGB(x, y, pixel);
            }
        }
    }

    private static void writeImage(BufferedImage image) {
        try {
            ImageIO.write(image, "png", new File("D://Image/output.jpg"));
            System.out.println("Writing Complete");
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
