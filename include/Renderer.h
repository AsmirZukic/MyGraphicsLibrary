#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "Object.h"

class Renderer {
public:
    void create(SDL_Window* window, int index, Uint32 flags);
    void clearScreen(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void updateScreen();
    void renderObjects(const std::vector<Object*>& objects);
    SDL_Renderer* getRenderer() const;

private:
    SDL_Renderer* renderer = nullptr;
};
