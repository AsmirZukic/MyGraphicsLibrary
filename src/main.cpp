#include "../include/App.h"
#include "../include/Rectangle.h"
#include "../include/Circle.h"

int main() {
    App app;
    app.createWindow("My App", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600);

    Rectangle rect(50, 50, 100, 100, 255, 0, 0, 255);
    Circle circle(app.getWindowWidth() / 2, app.getWindowHeight() / 2, 50, 0, 255, 0, 255);

    app.addObject(&rect);
    app.addObject(&circle);

    app.run();

    return 0;
}
