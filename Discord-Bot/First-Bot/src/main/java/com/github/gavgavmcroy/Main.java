package com.github.gavgavmcroy;

import discord4j.core.DiscordClient;
import discord4j.core.GatewayDiscordClient;
import discord4j.core.event.domain.message.MessageCreateEvent;
import discord4j.core.object.entity.Message;
import reactor.core.publisher.Mono;

import java.io.File;
import java.util.Scanner;

public class Main {
    /* Token needs to come from config file instead of hard coded*/
    public static void main(String[] args) throws Exception {
        File file = new File("C:\\Users\\Gavin T McRoy\\ocuments\\GitHub\\Fun-Projects\\Discord-Bot\\First-Bot\\info.cfg");
        Scanner scanner = new Scanner(file);

        String localToken = scanner.nextLine();
        
        DiscordClient client = DiscordClient.create(localToken);

        Mono<Void> login = client.withGateway((GatewayDiscordClient gateway) ->
                gateway.on(MessageCreateEvent.class, event -> {
                    Message message = event.getMessage();

                    if (message.getContent().equalsIgnoreCase("!ping")) {
                        return message.getChannel()
                                .flatMap(channel -> channel.createMessage("pong!"));
                    }

                    return Mono.empty();
                }));

        login.block();
    }
}
