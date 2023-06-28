#include "../include/Renderer.h"
#include <stdexcept>

void Renderer::create(SDL_Window* window, int index, Uint32 flags) {
    renderer = SDL_CreateRenderer(window, index, flags);
    if (!renderer) {
        throw std::runtime_error("Failed to create SDL renderer.");
    }
}

void Renderer::clearScreen(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
}

void Renderer::updateScreen() {
    SDL_RenderPresent(renderer);
}

void Renderer::renderObjects(const std::vector<Object*>& objects) {
    for (auto object : objects) {
        object->render(renderer);
    }
}

SDL_Renderer* Renderer::getRenderer() const {
    return renderer;
}
