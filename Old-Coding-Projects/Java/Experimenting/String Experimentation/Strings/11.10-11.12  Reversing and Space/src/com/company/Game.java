package com.company;

public class Game {

    private int playerHP = 100;
    private int inventorySize;
    private String playerName;

    public Game(int playerHP, String playerName){
        if(playerHP<=100 && playerHP>=0){
            this.playerHP = playerHP;
        }
        if(playerName.length()<=16){
            this.playerName = playerName;
        }else{
            System.out.println("Name is too long");
            this.playerName = "Unknown";
        }
    }

    @Override
    public String toString() {
        return this.playerName+" HP is "+this.playerHP;
    }

    public int getPlayerHP() {
        return playerHP;
    }

    public void setPlayerHP(int playerHP) {
        this.playerHP = playerHP;
    }

    public int getInventorySize() {
        return inventorySize;
    }

    public void setInventorySize(int inventorySize) {
        this.inventorySize = inventorySize;
    }

    public String getPlayerName() {
        return playerName;
    }

    public void setPlayerName(String playerName) {
        this.playerName = playerName;
    }
}
