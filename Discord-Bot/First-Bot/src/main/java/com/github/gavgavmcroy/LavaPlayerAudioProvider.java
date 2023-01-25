package com.github.gavgavmcroy;

import com.sedmelluq.discord.lavaplayer.format.StandardAudioDataFormats;
import com.sedmelluq.discord.lavaplayer.player.AudioPlayer;
import com.sedmelluq.discord.lavaplayer.track.playback.MutableAudioFrame;
import discord4j.voice.AudioProvider;

import java.nio.ByteBuffer;

public class LavaPlayerAudioProvider extends AudioProvider {

    private final AudioPlayer player;
    private final MutableAudioFrame frame = new MutableAudioFrame();

    public LavaPlayerAudioProvider(final AudioPlayer player) {
        super(ByteBuffer.allocate(StandardAudioDataFormats.DISCORD_OPUS.maximumChunkSize()));
        /* Set LavaPlayer MutableAudioFrame to use the same buffer as the one we just allocated */
        frame.setBuffer(getBuffer());
        this.player = player;
    }

    @Override
    public boolean provide() {
        /* AudioPlayer writes audio data to its AudioFrame */
        final boolean didProvide = player.provide(frame);

        /* If audio was provided, flip from write mode to read mode*/
        if (didProvide) {
            getBuffer().flip();
        }

        return didProvide;
    }


}
