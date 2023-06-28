#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "Window.h"
#include "Renderer.h"
#include "Object.h"
#include "InputHandler.h"

class App {
public:
    void createWindow(const char* title, int x, int y, int width, int height);
    void addObject(Object* object);
    void run();
    int getWindowWidth() const;
    int getWindowHeight() const;

private:
    Window window;
    Renderer renderer;
    std::vector<Object*> objects;
    bool quit = false;
    InputHandler inputHandler;

    void handleEvent(const SDL_Event& event);
    void update();
    void render();
};
