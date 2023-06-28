#include "../include/Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    : rect({ x, y, width, height }), color({ r, g, b, a }) {}

void Rectangle::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}
