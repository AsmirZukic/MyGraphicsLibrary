#include <SDL2/SDL.h>
#include <stdexcept>
#include <deque>
#include <memory>
#include <vector>

class InputHandler {
public:
    void handleInput() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            eventQueue.push_back(event);
        }
    }

    bool hasEvents() const {
        return !eventQueue.empty();
    }

    SDL_Event getNextEvent() {
        SDL_Event event = eventQueue.front();
        eventQueue.pop_front();
        return event;
    }

private:
    std::deque<SDL_Event> eventQueue;
};

class Window {
public:
    Window(const char* title, int x, int y, int width, int height)
        : window(SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN), SDL_DestroyWindow) {
        if (!window) {
            throw std::runtime_error("Failed to create SDL window.");
        }
    }

    SDL_Window* getSDLWindow() const {
        return window.get();
    }

private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
};

class Renderer {
public:
    Renderer(SDL_Window* window, int index, Uint32 flags)
        : renderer(SDL_CreateRenderer(window, index, flags), SDL_DestroyRenderer) {
        if (!renderer) {
            throw std::runtime_error("Failed to create SDL renderer.");
        }
    }

    void clearScreen(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
        SDL_SetRenderDrawColor(renderer.get(), r, g, b, a);
        SDL_RenderClear(renderer.get());
    }

    void updateScreen() {
        SDL_RenderPresent(renderer.get());
    }

private:
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;
};

class Game {
public:
    void createWindow(const char* title, int x, int y, int width, int height) {
        windows.emplace_back(title, x, y, width, height);
        renderers.emplace_back(windows.back().getSDLWindow(), -1, SDL_RENDERER_ACCELERATED);
    }

    void run() {
        InputHandler inputHandler;

        while (!quit) {
            inputHandler.handleInput();

            while (inputHandler.hasEvents()) {
                handleEvent(inputHandler.getNextEvent());
            }

            update();
            render();
        }
    }

private:
    std::vector<Window> windows;
    std::vector<Renderer> renderers;
    bool quit = false;

    void handleEvent(const SDL_Event& event) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
    }

    void update() {
        // Update game logic here...
    }

    void render() {
        for (auto& renderer : renderers) {
            renderer.clearScreen(0, 0, 0, 255);
            // Perform rendering operations here...
            renderer.updateScreen();
        }
    }
};

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    try {
        Game game;
        game.createWindow("Window 1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600);
        game.run();
    } catch (const std::exception& ex) {
        printf("Exception occurred: %s\n", ex.what());
        return 1;
    }

    SDL_Quit();

    return 0;
}
