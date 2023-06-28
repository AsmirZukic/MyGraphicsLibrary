#pragma once

#include "Object.h"

class Circle : public Object {
public:
    Circle(int centerX, int centerY, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void render(SDL_Renderer* renderer) override;

private:
    SDL_Point center;
    int radius;
    SDL_Color color;
};
