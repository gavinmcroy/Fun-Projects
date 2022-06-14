package com.github.gavgavmcroy;

import com.sedmelluq.discord.lavaplayer.player.AudioLoadResultHandler;
import com.sedmelluq.discord.lavaplayer.player.AudioPlayer;
import com.sedmelluq.discord.lavaplayer.tools.FriendlyException;
import com.sedmelluq.discord.lavaplayer.track.AudioPlaylist;
import com.sedmelluq.discord.lavaplayer.track.AudioTrack;

public class TrackScheduler implements AudioLoadResultHandler {

    private final AudioPlayer player;
    private final TrackState trackState;

    public TrackScheduler(final AudioPlayer player) {
        trackState = new TrackState();
        this.player = player;
    }

    @Override
    public void trackLoaded(AudioTrack track) {
        player.playTrack(track);
        trackState.trackLoaded();
    }

    @Override
    public void playlistLoaded(AudioPlaylist playlist) {
        trackState.playListLoaded();
    }

    @Override
    public void noMatches() {
        trackState.noMatches();
    }

    @Override
    public void loadFailed(FriendlyException exception) {
        trackState.loadFailed();
    }

    /* Once a state has been grabbed, the track will no longer remain in that state. For example
     *  If you want to check if a track loaded, and it failed, handle it. The state wouldn't need to remain
     *  in an inoperable state. The class checking the state should not have to reset it. It is assumed once a state is
     *  requested the client side will properly handle it*/
    public int getState() {
        return trackState.getStatus();
    }

    public void clearStatus() {
        trackState.clearStatus();
    }

}
