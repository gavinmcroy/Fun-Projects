package com.company;
import java.io.*;
import javax.sound.sampled.*;
import javax.swing.*;


public class SoundClipTest extends JFrame {

    private static String filePath = "/Users/gavintaylormcroy/Desktop/Axe Swing.wav";

    public SoundClipTest() {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Test Sound Clip");
        this.setSize(300, 200);
        this.setVisible(true);

        try {
            File file = new File(filePath);
            AudioInputStream audioIn = AudioSystem.getAudioInputStream(file);

            Clip clip = AudioSystem.getClip();
            clip.open(audioIn);
            clip.start();
        } catch (UnsupportedAudioFileException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (LineUnavailableException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new SoundClipTest();
    }
}
