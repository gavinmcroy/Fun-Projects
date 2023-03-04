package com.company;

import java.util.Scanner;

public class Calculator {

    private Scanner scanner = new Scanner(System.in);
    private double totalNumber = 0;
    private boolean firstStart = true;

    public Calculator() {
        mainApplication();
    }

    private void mainApplication() {
        mainMenu();
        while (determineUserChoice(readUserChoice()) != -1) {
            mainMenu();
        }
    }

    private void mainMenu() {
        System.out.println("Result: " + this.totalNumber);
        System.out.println("Choose one of the following Options\n" +
                "1. Add\n" +
                "2. Subtract\n" +
                "3. Multiply\n" +
                "4. Divide\n" +
                "5. Quit\n" +
                "6. Clear Result");
    }

    private int readUserChoice() {
        boolean hasInt = scanner.hasNextInt();
        if (hasInt) {
            return scanner.nextInt();
        } else {
            scanner.nextLine();
            System.out.println("Enter a integer");
            return -1;
        }
    }

    private int determineUserChoice(int userChoice) {
        switch (userChoice) {
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                divide();
                break;
            case 5:
                return -1;
            case 6:
                resetToBeginning();
                break;
            default:
                System.out.println("Enter a valid choice");
        }
        return 0;
    }

    private void add() {
        double numberToAdd = firstStart();
        this.totalNumber += numberToAdd;
    }

    private void subtract() {
        double numberToSubtract = firstStart();
        this.totalNumber -= numberToSubtract;
    }

    private void multiply() {
        double numberToMultiply = firstStart();
        this.totalNumber *= numberToMultiply;
    }

    private void divide() {
        double numberToDivide = firstStart();
        if (numberToDivide == 0) {
            System.out.println("Error Cannot Divide by 0");
            resetToBeginning();
        } else {
            this.totalNumber /= numberToDivide;
        }
    }

    private double firstStart() {
        double number = recordNumberInput();
        if (this.firstStart) {
            this.totalNumber = number;
            this.firstStart = false;
            number = recordNumberInput();
        }

        return number;
    }

    private void resetToBeginning() {
        System.out.println("Cleared Result");
        this.totalNumber = 0;
        this.firstStart = true;
    }

    private double recordNumberInput() {
        boolean validInput = false;
        while (!validInput) {
            System.out.println("Enter the desired number ");
            scanner.nextLine();
            boolean hasDouble = scanner.hasNextDouble();
            if (hasDouble) {
                return scanner.nextDouble();
            } else {
                System.out.println("Enter a number please");
                validInput = false;
            }
        }
        return scanner.nextDouble();
    }
}
