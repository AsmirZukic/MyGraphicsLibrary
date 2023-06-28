#include "../include/Circle.h"

Circle::Circle(int centerX, int centerY, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    : center({ centerX, centerY }), radius(radius), color({ r, g, b, a }) {}

void Circle::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    int x = 0;
    int y = radius;
    int d = 3 - (2 * radius);

    while (x <= y) {
        // Render vertical lines at each y-coordinate within the circle's radius
        for (int currY = center.y - y; currY <= center.y + y; ++currY) {
            SDL_RenderDrawPoint(renderer, center.x + x, currY); // Right side
            SDL_RenderDrawPoint(renderer, center.x - x, currY); // Left side
        }

        // Increment x and adjust the error value
        ++x;
        if (d < 0) {
            d += (4 * x) + 6;
        } else {
            --y;
            d += (4 * (x - y)) + 10;
        }

        // Render horizontal lines at each x-coordinate within the circle's radius
        for (int currX = center.x - y; currX <= center.x + y; ++currX) {
            SDL_RenderDrawPoint(renderer, currX, center.y + x); // Bottom side
            SDL_RenderDrawPoint(renderer, currX, center.y - x); // Top side
        }
    }
}
