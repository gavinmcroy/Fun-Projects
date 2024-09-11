package com.company;

import java.util.Scanner;

class Print {

    private static Scanner scanner = new Scanner(System.in);

    static void printMessage(String message) throws InterruptedException {
        char[] charToArray = message.toCharArray();

        for (int i = 0; i < charToArray.length; i++) {
            System.out.print(charToArray[i]);
            Thread.sleep(25);
        }
    }

    static void exitPrompt() throws InterruptedException {
        String exit = scanner.nextLine();
        scanner.close();
        if(exit.equals("")){
            System.exit(0);
        }else{
            System.out.println("Closing in 2 seconds");
            Thread.sleep(2000);
        }
    }

}
