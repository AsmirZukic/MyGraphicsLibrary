#pragma once

#include <SDL2/SDL.h>

class Window {
public:
    void create(const char* title, int x, int y, int width, int height);
    SDL_Window* getSDLWindow() const;
    int getWidth() const;
    int getHeight() const;

private:
    SDL_Window* window = nullptr;
};
