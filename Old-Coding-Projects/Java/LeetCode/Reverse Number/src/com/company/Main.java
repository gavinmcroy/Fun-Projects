package com.company;

public class Main {

    /*
    Given a 32-bit signed integer, reverse digits of an integer.
    Example 1:
    Input: 123
    Output: 321
     */
    public static void main(String[] args) {
        System.out.println(reverseInt(1534236469));
    }

    private static int reverseInt(int num){
        int tmp = num;
        long reverse = 0;
        int totalDigits = 1;
        while(!(tmp<10 && tmp>-10)){
            tmp/=10;
            totalDigits*=10;
        }
        while(num!=0){
            int digit = num % 10;
            num/=10;
            reverse +=totalDigits*digit;
            if(reverse>Integer.MAX_VALUE){
                return 0;
            }
            totalDigits/=10;
        }
        return (int) reverse;
    }
}
