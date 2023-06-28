#include "../include/Window.h"
#include <stdexcept>

void Window::create(const char* title, int x, int y, int width, int height) {
    window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        throw std::runtime_error("Failed to create SDL window.");
    }
}

SDL_Window* Window::getSDLWindow() const {
    return window;
}

int Window::getWidth() const {
    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    return width;
}

int Window::getHeight() const {
    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    return height;
}
