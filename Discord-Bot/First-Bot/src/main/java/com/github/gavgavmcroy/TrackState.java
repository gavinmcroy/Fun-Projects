package com.github.gavgavmcroy;

import java.util.ArrayList;

public class TrackState {

    public static final int NO_OPERATION = 0;
    public static final int TRACK_LOADED = 1;
    public static final int PLAY_LIST_LOADED = 2;
    public static final int NO_MATCHES = 3;
    public static final int LOAD_FAILED = 4;

    private static int status;

    TrackState(){
        status = NO_OPERATION;
    }

    public void trackLoaded() {
        status = TRACK_LOADED;
    }

    public void playListLoaded() {
        status = PLAY_LIST_LOADED;
    }

    public void noMatches() {
        System.out.println("No Match");
        status = NO_MATCHES;
    }

    public void loadFailed() {
        System.out.println("Failed");
        status = LOAD_FAILED;
    }

    public int getStatus(){
        return status;
    }

    public void clearStatus(){
        status = NO_OPERATION;
    }

}
