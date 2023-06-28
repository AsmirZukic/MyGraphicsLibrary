#include "../include/InputHandler.h"

void InputHandler::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        eventQueue.push(event);
    }
}

bool InputHandler::hasEvents() const {
    return !eventQueue.empty();
}

SDL_Event InputHandler::getNextEvent() {
    SDL_Event event = eventQueue.front();
    eventQueue.pop();
    return event;
}
