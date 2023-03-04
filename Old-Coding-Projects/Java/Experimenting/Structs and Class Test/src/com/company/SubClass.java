package com.company;

public class SubClass extends SuperClass {

    int color;
    int xPos;
    int yPos;

    public SubClass(int direction, int color, int xPos, int yPos) {
        super(100, 2, direction);
        this.color = color;
        this.xPos = xPos;
        this.yPos = yPos;
    }

    @Override
    public void printMethod() {
//        super.printMethod();
        System.out.println("Printed in SubClass");
    }
}

