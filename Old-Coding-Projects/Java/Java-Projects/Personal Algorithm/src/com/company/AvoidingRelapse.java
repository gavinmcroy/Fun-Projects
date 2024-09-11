package com.company;


import java.util.Scanner;

public class AvoidingRelapse {

    private static Scanner scanner = new Scanner(System.in);

    public static void start() throws InterruptedException {
        mainMenu();
        while(choiceSelectorRelapse()==-1){
            scanner.next();
            choiceSelectorRelapse();
        }
    }

    private static void mainMenu() throws InterruptedException {
        String mainMenu = "Which bad temptation is blinding you? \n" +
                "1. Gaming\n" +
                "2. Discord\n" +
                "3. No fap\n" +
                "4. Youtube\n";
        Print.printMessage(mainMenu);
    }

    private static int choiceSelectorRelapse() throws InterruptedException {
        if (!scanner.hasNextInt()) {
            return -1;
        }
        int choice = scanner.nextInt();
        switch (choice) {
            case 1:
                Gaming.inspiration();
                break;
            case 2:
                Discord.inspiration();
                break;
            case 3:
                NoFap.inspiration();
                break;
            case 4:
                Youtube.inspiration();
                break;
            default:
                System.out.println("Invalid Selection");
        }
        return 0;
    }


}
