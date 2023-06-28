#pragma once

#include <SDL2/SDL.h>

class Object {
public:
    virtual ~Object() {}
    virtual void render(SDL_Renderer* renderer) = 0;
};
