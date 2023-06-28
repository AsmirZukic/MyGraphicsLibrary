#pragma once

#include "Object.h"

class Rectangle : public Object {
public:
    Rectangle(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void render(SDL_Renderer* renderer) override;

private:
    SDL_Rect rect;
    SDL_Color color;
};
