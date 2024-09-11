package com.company;

import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws InterruptedException {
        mainMenu();
        while(choiceSelector()==-1){
            scanner.next();
            choiceSelector();
        }
    }

    private static void mainMenu() throws InterruptedException {
        String mainMenu = "Hi Gavin. What is it that you are going through?\n" +
                "1. What is my why? \n" +
                "2. Temptations of a bad choice are upon me";
        Print.printMessage(mainMenu);

    }

    private static int choiceSelector() throws InterruptedException {
        if (!scanner.hasNextInt()) {
            return -1;
        }
        int choice = scanner.nextInt();
        switch (choice) {
            case 1:
                Why.inspiration();
                break;
            case 2:
                AvoidingRelapse.start();
                break;
        }
        return 0;
    }


}
