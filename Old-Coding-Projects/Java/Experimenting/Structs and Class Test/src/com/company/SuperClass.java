package com.company;

public class SuperClass {

    int health;
    int moveSpeed;
    int direction;

    public SuperClass(int health, int moveSpeed, int direction) {
        this.health = health;
        this.moveSpeed = moveSpeed;
        this.direction = direction;
    }

    public void printMethod(){
        System.out.println("Printed in SuperClass");
    }

    public void eat(boolean eating){
        if(eating){
            System.out.println("Eating!");
        }else{
            System.out.println("Not Eating!");
        }
    }
}
