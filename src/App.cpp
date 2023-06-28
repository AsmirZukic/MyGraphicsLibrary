#include "../include/App.h"

void App::createWindow(const char* title, int x, int y, int width, int height) {
    window.create(title, x, y, width, height);
    renderer.create(window.getSDLWindow(), -1, SDL_RENDERER_ACCELERATED);
}

void App::addObject(Object* object) {
    objects.push_back(object);
}

void App::run() {
    while (!quit) {
        inputHandler.handleInput();

        while (inputHandler.hasEvents()) {
            handleEvent(inputHandler.getNextEvent());
        }

        update();
        render();
    }
}

int App::getWindowWidth() const {
    return window.getWidth();
}

int App::getWindowHeight() const {
    return window.getHeight();
}

void App::handleEvent(const SDL_Event& event) {
    if (event.type == SDL_QUIT) {
        quit = true;
    }
}

void App::update() {
    // Update application logic here...
}

void App::render() {
    renderer.clearScreen(0, 0, 0, 255);
    renderer.renderObjects(objects);
    renderer.updateScreen();
}
