package com.github.gavgavmcroy;

import discord4j.core.event.domain.message.MessageCreateEvent;

public interface Command {
    void execute(MessageCreateEvent event) throws InterruptedException;

}
