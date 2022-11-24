package com.github.gavgavmcroy;

import com.sedmelluq.discord.lavaplayer.player.AudioPlayer;
import com.sedmelluq.discord.lavaplayer.player.AudioPlayerManager;
import com.sedmelluq.discord.lavaplayer.player.DefaultAudioPlayerManager;
import com.sedmelluq.discord.lavaplayer.source.AudioSourceManagers;
import com.sedmelluq.discord.lavaplayer.track.AudioTrack;
import com.sedmelluq.discord.lavaplayer.track.AudioTrackInfo;
import com.sedmelluq.discord.lavaplayer.track.playback.NonAllocatingAudioFrameBuffer;
import discord4j.core.DiscordClientBuilder;
import discord4j.core.GatewayDiscordClient;
import discord4j.core.event.domain.message.MessageCreateEvent;
import discord4j.core.object.VoiceState;
import discord4j.core.object.entity.Member;
import discord4j.core.object.entity.Message;
import discord4j.core.object.entity.channel.VoiceChannel;
import discord4j.voice.AudioProvider;

import java.util.*;

public class Main {
    private static final Map<String, Command> commands = new HashMap<>();

    public static void main(String[] args) throws Exception {
        GatewayDiscordClient client = DiscordClientBuilder.create(Util.openToken()).build().login().block();

        /* This is our message listener */
        Objects.requireNonNull(client).getEventDispatcher().on(MessageCreateEvent.class).subscribe(event -> {
            final String content = event.getMessage().getContent();
            for (Map.Entry<String, Command> entry : commands.entrySet()) {
                if (content.startsWith("!" + entry.getKey())) {
                    try {
                        entry.getValue().execute(event);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                    break;
                }
            }
        });

        client.onDisconnect().block();
    }

    static {
        /* translates URLS to AudioTrack instances */
        final AudioPlayerManager playerManager = new DefaultAudioPlayerManager();
        /* Optimization */
        playerManager.getConfiguration().setFrameBufferFactory(NonAllocatingAudioFrameBuffer::new);
        /* Allow playerManager to parse remote sources like YouTube */
        AudioSourceManagers.registerRemoteSources(playerManager);
        /* Create an AudioPlayer so Discord4J can receive audio data */

        final AudioPlayer audioPlayer = playerManager.createPlayer();
        AudioProvider provider = new LavaPlayerAudioProvider(audioPlayer);


        commands.put("ping", event -> Objects.requireNonNull(event.getMessage().getChannel().block()).
                createMessage("Pong").block());

        commands.put("dick", event -> {
            System.out.println("Hit");
            final int RANDOM_NUMBER_BOUNDS = 100;
            Random random = new Random();
            int randomNum = random.nextInt(RANDOM_NUMBER_BOUNDS);
            String size = "\u0190";
            for (int i = 0; i < randomNum; i++) {
                size = size.concat("=");
            }
            size = size.concat("D");
            String finalSize = size;
            Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(finalSize).block();
        });

        commands.put("flip", event -> {
            final int RANDOM_NUMBER_BOUNDS = 2;
            Random random = new Random();
            int randomNum = random.nextInt(RANDOM_NUMBER_BOUNDS);
            String mentionTag = event.getMember().get().getMention();
            if (randomNum == 0) {
                Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag + " Heads").block();
            } else {
                Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag + " Tails").block();
            }
        });

        commands.put("play", event -> {
            String mentionTag = event.getMember().get().getMention();
            final int EXPECTED_ARGUMENTS = 2;
            final TrackScheduler scheduler = new TrackScheduler(audioPlayer);
            final String content = event.getMessage().getContent();
            /* Syntax expected is !play url:, so we parse the entire message splitting it by spaces, the url is expected
             * to the second command */
            final List<String> command = Arrays.asList(content.split(" "));
            if (command.size() < EXPECTED_ARGUMENTS) {
                Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag + " Error " +
                        "no url was provided. Make sure there is only one space").block();
            } else {
                /* TODO odd bug revolving around loadItem taking time to process. So while its loading on another
                 *   thread, scheduler checks the state before its had time to assign the state */
                playerManager.loadItem(command.get(1), scheduler);
                Thread.sleep(2000);
                /* Notify that item was loaded */
                if (scheduler.getState() == TrackState.NO_MATCHES) {
                    Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag + " Error: " +
                            "The URL provided did not yield any matches ").block();
                } else if (scheduler.getState() == TrackState.LOAD_FAILED) {
                    Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag + " Error: " +
                            "There was a load error with the URL. Make sure the URL did not come from " +
                            "a playlist").block();
                } else if (scheduler.getState() == TrackState.TRACK_LOADED) {
                    Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag + " Success " +
                            " Song will now play").block();
                } else if (scheduler.getState() == TrackState.PLAY_LIST_LOADED) {
                    Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag + " " +
                            "Playlist Successfully Loaded ").block();
                } else if (scheduler.getState() == TrackState.NO_OPERATION) {
                    Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag +
                            " Critical Error: Resetting objects to prevent crash. If you see this " +
                            "it is likely youtube is under heavy load and or the music player is").block();
                    audioPlayer.stopTrack();
                }
            }
        });

        commands.put("join", event -> {
            Member member = event.getMember().orElse(null);
            if (member != null) {
                VoiceState voiceState = member.getVoiceState().block();
                if (voiceState != null) {
                    VoiceChannel channel = voiceState.getChannel().block();
                    if (channel != null) {
                        channel.join(spec -> spec.setProvider(provider)).block();
                        BotState.isConnected = true;
                    }
                } else {
                    String mentionTag = member.getMention();
                    Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag + " Error: " +
                            "You are not in a Voice Channel").block();
                }
            }
        });

        commands.put("leave", event -> {
            /* Get person who sent the message */
            Member member = event.getMember().orElse(null);
            if (member != null) {
                String mentionTag = event.getMember().get().getMention();
                /* if not connected, do nothing */
                if (BotState.isConnected) {
                    Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag + " Superior " +
                            "has disconnected").block();
                    Objects.requireNonNull(member.getGuild().block()).getVoiceConnection().block().disconnect().block();
                    BotState.isConnected = false;
                } else {
                    Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag +
                            " Not connected ").block();
                }
            }
        });

        commands.put("stop", event -> {
            AudioTrack track = audioPlayer.getPlayingTrack();
            String mentionTag = event.getMember().get().getMention();
            if (track == null) {
                Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag +
                        " No track is playing").block();
            } else {
                Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag + " Song has been " +
                        "removed from queue").block();
                audioPlayer.stopTrack();
            }
        });

        commands.put("song", event -> {
            String mentionTag = event.getMember().get().getMention();
            AudioTrack track = audioPlayer.getPlayingTrack();
            if (track == null) {
                Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag +
                        " No track is playing").block();
            }
            AudioTrackInfo info = track.getInfo();
            if (info == null) {
                Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage("Error: " +
                        "Unable to grab info").block();
            } else {
                Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag +
                        "\nTITLE: " + info.title + "\nDURATION: " + info.length / 1000 + " seconds" + "\nCREATOR: " + info.author).block();
            }
        });

        System.out.println("Hello2");
    }
}
