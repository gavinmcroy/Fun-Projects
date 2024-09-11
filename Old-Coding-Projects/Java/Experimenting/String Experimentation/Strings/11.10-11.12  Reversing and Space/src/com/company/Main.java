package com.company;

public class Main {

    public static void main(String[] args) {
	    String myName = "My name is Gavin";
        System.out.println(myName);
        StringBuilder stringBuilder = new StringBuilder(myName);
        System.out.println(stringBuilder.reverse());
        Game game = new Game(44,"Rick131");
        System.out.println(game);
        String annoyingWayToType = "   WOOOOOOOOO      ";
        System.out.println(annoyingWayToType.trim());
        String phrase = "What doesnt kill you makes you stronger";
        System.out.println(phrase.replace("oesnt","oes"));
    }

}
