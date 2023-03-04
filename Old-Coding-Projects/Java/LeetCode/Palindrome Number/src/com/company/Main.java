package com.company;

public class Main {
/*
    Determine whether an integer is a palindrome. An integer is a palindrome when
    it reads the same backward as forward.
    Example 1:
    Input: 121
    Output: true
 */

    public static void main(String[] args) {
        boolean isPalindrome = palindromeNum(313);
        System.out.println(isPalindrome);
    }

    public static boolean palindromeNum(int num){
        int tmp = num;
        int numPositions = 1;
        int reversal = 0;
        while(tmp>9){
            tmp/=10;
            numPositions*=10;
        }
        tmp = num;
        while(tmp>0){
            int digit = tmp%10;
            tmp/=10;
            System.out.println("Digit: "+digit);
            reversal+=digit*numPositions;
            System.out.println("Reversal: "+reversal);
            numPositions/=10;
        }
        System.out.println(reversal);
        return reversal == num;
    }
}
