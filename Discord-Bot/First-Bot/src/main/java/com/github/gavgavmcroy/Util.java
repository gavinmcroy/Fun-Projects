package com.github.gavgavmcroy;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Util {

    public static String openToken() throws FileNotFoundException {
        File file = new File("C:\\Users\\Gavin T McRoy\\Documents\\GitHub\\Fun-Projects\\" +
                "Discord-Bot\\First-Bot\\info.cfg");
        Scanner scanner = new Scanner(file);
        return scanner.nextLine();
    }
}
