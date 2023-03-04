package com.company;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {

    private static int inventorySlot = 0;
    private static ArrayList<Testing> storage = new ArrayList<>();

    public static void main(String[] args) {
//	    String message = inventorySlot>1 ? "Player is loaded" : "Player is broke";
//        System.out.println(message);
//        for(int i = 0; i<20;i++){
//            storage.add(new Testing());
//        }
//        System.out.println(Testing.getAmountOf());
        int[] num = {3,2,4};
        int[] sum = twoSum(num,6);
        System.out.println(Arrays.toString(sum));
    }



    public static int[] twoSum(int[] nums, int target) {
        for(int i = 0; i<nums.length; i++){
            for(int j = i+1; j<nums.length;j++){
                if(nums[i]+nums[j]==target){
                    System.out.println(nums[i]+nums[j]);
                    int[] sum = {i,j};
                    return sum;
                }
            }
        }
        return nums;
    }
    

}
