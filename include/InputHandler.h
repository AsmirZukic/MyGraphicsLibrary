#pragma once

#include <SDL2/SDL.h>
#include <queue>

class InputHandler {
public:
    void handleInput();
    bool hasEvents() const;
    SDL_Event getNextEvent();

private:
    std::queue<SDL_Event> eventQueue;
};
