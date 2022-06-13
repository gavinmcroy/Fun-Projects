package com.github.gavgavmcroy;

import com.sedmelluq.discord.lavaplayer.player.AudioPlayer;
import com.sedmelluq.discord.lavaplayer.player.AudioPlayerManager;
import com.sedmelluq.discord.lavaplayer.player.DefaultAudioPlayerManager;
import com.sedmelluq.discord.lavaplayer.source.AudioSourceManagers;
import com.sedmelluq.discord.lavaplayer.track.playback.NonAllocatingAudioFrameBuffer;
import discord4j.core.DiscordClientBuilder;
import discord4j.core.GatewayDiscordClient;
import discord4j.core.event.domain.message.MessageCreateEvent;
import discord4j.core.object.VoiceState;
import discord4j.core.object.entity.Member;
import discord4j.core.object.entity.channel.VoiceChannel;
import discord4j.discordjson.json.gateway.MessageCreate;
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
                    entry.getValue().execute(event);
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
        final AudioPlayer player = playerManager.createPlayer();
        AudioProvider provider = new LavaPlayerAudioProvider(player);

        commands.put("ping", event -> Objects.requireNonNull(event.getMessage().getChannel().block()).
                createMessage("Pong").block());

        commands.put("dick", event -> {
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

        commands.put("join", event -> {
            Member member = event.getMember().orElse(null);
            if (member != null) {
                VoiceState voiceState = member.getVoiceState().block();
                if (voiceState != null) {
                    VoiceChannel channel = voiceState.getChannel().block();
                    if (channel != null) {
                        channel.join(spec -> spec.setProvider(provider)).block();
                    }
                }else{
                    String mentionTag = member.getMention();
                    Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag + " Error " +
                            "You are not in a Voice Channel").block();
                }
            }
        });

        commands.put("play", event -> {
            final int EXPECTED_ARGUMENTS = 2;
            final TrackScheduler scheduler = new TrackScheduler(player);
            final String content = event.getMessage().getContent();
            /* Syntax expected is !play url:, so we parse the entire message splitting it by spaces, the url is expected
             * to the second command */
            final List<String> command = Arrays.asList(content.split(" "));
            if (command.size() < EXPECTED_ARGUMENTS) {
                String mentionTag = event.getMember().get().getMention();
                Objects.requireNonNull(event.getMessage().getChannel().block()).createMessage(mentionTag + " Error " +
                        "no url was provided").block();
            } else {
                playerManager.loadItem(command.get(1), scheduler);
            }
        });

        commands.put("leave", event -> {
            /* Get person who sent the message */
            Member member = event.getMember().orElse(null);
            if (member != null) {
                VoiceState voiceState = member.getVoiceState().block();
                if (voiceState != null) {
                    VoiceChannel channel = voiceState.getChannel().block();
                    if (channel != null) {
                        Objects.requireNonNull(member.getGuild().block()).getVoiceConnection().block().disconnect().block();
                    }
                }
            }
        });

        commands.put("stop", event ->{
           player.stopTrack();

        });
    }
}
