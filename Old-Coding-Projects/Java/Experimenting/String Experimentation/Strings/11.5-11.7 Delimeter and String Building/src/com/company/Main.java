package com.company;

import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

public class Main {

    public static void main(String[] args) {

    }

    private static void printArray(String[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }

    private static void testingStringSplit() {
        String test = "Gav;Jake;Rick;Hola;";
        String test2 = "CokeAPepsiADrinkA";
        String[] arrayTest = test.split(";");
        String[] arrayTest2 = test2.split("A");
        printArray(arrayTest);
        System.out.println("Array test #2");
        printArray(arrayTest2);
    }

    private static void testingSpecialCharacterStringSplit() {
        String names = "Gav Stacey Niko Patrick Rick ";
        String[] names1 = names.split(" ");
        printArray(names1);
        String specialNames = "Niko|John|Gav";
        String regex = Pattern.quote("|");
        String[] specialNamesArray = specialNames.split(regex);
        printArray(specialNamesArray);
        String specialNamesBackToString = String.join("-", specialNamesArray);
        System.out.println(specialNamesBackToString);
    }

    private static void testingStringJoiner() {
        StringJoiner stringJoiner = new StringJoiner(", ", "[ ", " ]");
        stringJoiner.add("abcd");
        stringJoiner.add("efgh");
        System.out.println(stringJoiner);
        String phrase = "Spanish is";
        String phrase2 = " not my favourite";
        String phrase3 = phrase.concat(phrase2);
        System.out.println(phrase3);
        String saying = "you know what they say what kills you makes you stronger";
        StringTokenizer tokenizer = new StringTokenizer(saying, "");
        while (tokenizer.hasMoreTokens()) {
            System.out.println(tokenizer.nextToken());
        }
    }
}
