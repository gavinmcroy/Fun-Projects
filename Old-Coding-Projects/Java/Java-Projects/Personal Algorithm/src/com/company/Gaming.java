package com.company;

class Gaming {

    private static String message = "You know why you quit. If you need a reminder than let\n" +
            "me politely realign you. You're probably experiencing the delusion of good \n" +
            "times whether it be funny moments or that time you got a quad kill down long. \n" +
            "That's 1/100 moments. That delusion blinds you from the so many wasted hours spent\n" +
            "on mindlessly playing to distract yourself from your own responsibilities. \n" +
            "The so many angry moments, the moments vowing to never do it again, the complete\n" +
            "dismantlement of all your dreams. And for what? To play in a fake virtual world\n" +
            "that rips all intent of you to become something. Is it really worth that? The \n" +
            "one precious life you have on this beautiful earth with the infinite potential \n" +
            "to become something phenomenal yet you dare to waste it on something so mindless \n" +
            "because you lack the capability to deal with the world's pain. You have dreams. \n" +
            "All gaming does is trash them. Each time without failure you've gone back to \n" +
            "gaming it's been a giant regret. It's dug a deeper void that leaves you broken \n" +
            "for nearly weeks. Come on. Haven't we been through this cycle enough?\n"+
            "Press ENTER to close";

    static void inspiration() throws InterruptedException {
        Print.printMessage(message);
        Print.exitPrompt();
    }

}
