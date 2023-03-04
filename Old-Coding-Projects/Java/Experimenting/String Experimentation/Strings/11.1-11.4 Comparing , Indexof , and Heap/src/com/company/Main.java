package com.company;

import java.lang.*;
import java.util.*;
import java.text.SimpleDateFormat;

public class Main {

    public static void main(String[] args) {
        String name1 = "Gav";
        String longSentence = "This is a long sentence used to test index of";
        if (name1.contains(" ")) {
            System.out.println("Why is there a space in your name dork");
        } else {
            System.out.println("Good job I see no issues");
        }
        System.out.println(longSentence.indexOf("long sentence"));
        simpleStringReverse();
    }

    private static void equalsIgnoreCase() {
        String gav = "GAVIN T MCROY!";
        String gav2 = "gavin t mcroy!";
        if (gav.equalsIgnoreCase(gav2)) {
            System.out.println("true");
        }
    }

    private static void localeClass() {
        String firstString = "Taki";
        String secondString = "TAKI";
        System.out.println(firstString.equalsIgnoreCase(secondString)); //prints true
        Locale locale = Locale.forLanguageTag("tr-TR");
        System.out.println(firstString.toLowerCase(locale).equals(secondString.toLowerCase(locale)));
    }

    private static void simpleDateFormat() {
        Locale locales[] = SimpleDateFormat.getAvailableLocales();
        for (int i = 1; i < 20; i++) {
            System.out.printf("%10s - %s, %s \n", locales[i].toString(),
                    locales[i].getDisplayName(), locales[i].getDisplayCountry());
        }
    }

    private static void comparingStringsWithSwitch() {
        String letter = "A";
        switch (letter) {
            case "A":
                System.out.println("Wow! ");
                break;
            case "B":
                System.out.println("Wow 2.0! ");
            default:
                System.out.println("Default");
        }
    }

    private static void testingStringExceptions() {
        String gav = null;
        if ("Gavin".equalsIgnoreCase(gav)) {
            System.out.println("Java is op af");
        }
        if (Objects.equals(gav, "gav")) {
            System.out.println("True");
        } else {
            System.out.println("False");
        }
        try {
            if (gav.equalsIgnoreCase("gav")) {
                System.out.println("exception should be thrown");
            }
        } catch (NullPointerException a) {
            System.out.println(a + " was caught");
        }
    }

    private static void testingIntern() {
        String gav = new String("Gav");
        String niko = "Gav";
        if (gav == niko) {
            System.out.println("This shouldn't run");
        }
        String internGav = gav.intern();
        if (internGav == niko) {
            System.out.println("This should run");
        }
    }

    private static void simpleStringReverse(){
        String niko = "niko";
        StringBuilder stringBuilder = new StringBuilder(niko);
        niko = stringBuilder.reverse().toString();
        System.out.println(niko);
    }
}
