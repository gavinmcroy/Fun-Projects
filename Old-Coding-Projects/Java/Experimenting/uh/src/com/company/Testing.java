package com.company;

public class Testing {

    private static int amountOf = 0;

    Testing(){
        amountOf++;
    }

    public static int getAmountOf() {
        return amountOf;
    }
}
