package com.github.gavgavmcroy;

import com.sedmelluq.discord.lavaplayer.player.AudioLoadResultHandler;
import com.sedmelluq.discord.lavaplayer.player.AudioPlayer;
import com.sedmelluq.discord.lavaplayer.player.event.AudioEventAdapter;
import com.sedmelluq.discord.lavaplayer.tools.FriendlyException;
import com.sedmelluq.discord.lavaplayer.track.AudioPlaylist;
import com.sedmelluq.discord.lavaplayer.track.AudioTrack;
import com.sedmelluq.discord.lavaplayer.track.AudioTrackEndReason;

public class TrackScheduler extends AudioEventAdapter implements AudioLoadResultHandler {

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

    @Override
    public void onPlayerPause(AudioPlayer player) {
        /* TODO */
    }

    @Override
    public void onPlayerResume(AudioPlayer player) {
        /* TODO */
    }

    @Override
    public void onTrackStart(AudioPlayer player, AudioTrack track) {
        /* TODO */
    }

    @Override
    public void onTrackEnd(AudioPlayer player, AudioTrack track, AudioTrackEndReason endReason) {
        if (endReason.mayStartNext) {
            /* TODO */
        }

        // endReason == FINISHED: A track finished or died by an exception (mayStartNext = true).
        // endReason == LOAD_FAILED: Loading of a track failed (mayStartNext = true).
        // endReason == STOPPED: The player was stopped.
        // endReason == REPLACED: Another track started playing while this had not finished
        // endReason == CLEANUP: Player hasn't been queried for a while, if you want you can put a
        //                       clone of this back to your queue
    }

    @Override
    public void onTrackException(AudioPlayer player, AudioTrack track, FriendlyException exception) {
        /* TODO */
    }

    @Override
    public void onTrackStuck(AudioPlayer player, AudioTrack track, long thresholdMs) {
        /* TODO */
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
