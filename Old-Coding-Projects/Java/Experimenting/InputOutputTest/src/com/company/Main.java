package com.company;

import java.io.File;
import java.io.IOException;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.Desktop;


public class Main {

    public static void main(String[] args) {

    }

    //---Miscellaneous
    public static void testingInputOutput() {
        BufferedImage image = null;
        File file;

        try {
            file = new File("D://Image/800.png");
            image = ImageIO.read(file);
            System.out.println("Reading completed");
        } catch (IOException e) {
            System.out.println("Error: " + e);
        }

        try {
            ImageIO.write(image, "gif", new File("D://Image/output.gif"));
            ImageIO.write(image, "png", new File("D://Image/output.png"));
            System.out.println("Writing completed");
        } catch (IOException e) {
            System.out.println("Error " + e);
        }
    }

    public static void testingPixels() throws IOException {
        BufferedImage image = null;
        File file;

        try {
            file = new File("D://Image/800.png");
            image = ImageIO.read(file);
            System.out.println("Reading complete");
        } catch (IOException e) {
            System.out.println("Error" + e.getMessage());
        }
        //---Getting Pixel Value
        int p = image.getRGB(500, 200);
        int a = (p >> 24) & 0xff;
        int r = (p >> 16) & 0xff;
        int g = (p >> 8) & 0xff;
        int b = p & 0xff;
        System.out.println(a + " , " + r + " , " + g + " , " + b);

        //---Changing pixel Value
        a = 255;
        r = 11;
        g = 116;
        b = 173;
        p = (a << 24) | (r << 16) | (g << 8) | b;
        image.setRGB(500, 200, p);
        try {
            ImageIO.write(image, "png", new File("D://Image/output.png"));
            System.out.println("Writing Complete");
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        int width = image.getWidth();
        int height = image.getHeight();
        System.out.println("Width: " + width + " Hieght: " + height);
    }

    public static void openDesktop() throws IOException {
        Desktop desktop = Desktop.getDesktop();
        File directoryToOpen = null;
        try {
            directoryToOpen = new File("C:/");
            desktop.open(directoryToOpen);
        } catch (IllegalArgumentException a) {
            System.out.println(a.getMessage());
        }
    }

    public static void openDirectory() {
        JFileChooser file = new JFileChooser();
        file.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
        file.showSaveDialog(null);
        System.out.println(file.getCurrentDirectory());
        System.out.println(file.getSelectedFile());
    }

}
