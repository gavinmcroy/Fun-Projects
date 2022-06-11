package com.github.gavgavmcroy;

import discord4j.core.DiscordClient;
import discord4j.core.GatewayDiscordClient;
import discord4j.core.event.domain.message.MessageCreateEvent;
import discord4j.core.object.entity.Message;
import reactor.core.publisher.Mono;

public class Main {

    public static void main(String[] args) {
        DiscordClient client = DiscordClient.create("OTg1MjM0NzY5OTAwMTA5OTE0.G7OR6r.IMH_H_YYito3ANrj55155-XLE4rxx1OrFiOFlY");

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
