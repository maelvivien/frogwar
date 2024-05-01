// window.cpp
#include "window.hpp"
#include "sprite.hpp"

Window::Window(const std::string& image_path, int width, int height)
    : width(width), height(height), image_path(image_path) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // handle error
    }

    window = SDL_CreateWindow("Window Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        // handle error
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        // handle error
    }

    SDL_Surface* image = IMG_Load(image_path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    entity = new Sprite(renderer, "test1", "texture/perso.png", 800, 100, 300, 300);
}

Window::~Window() {
    delete entity;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Window::display() {
    bool running = true;
    SDL_Event event;

    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        if (keyState[SDL_SCANCODE_UP]) {
            entity->move(0, -1); // move up
        }
        if (keyState[SDL_SCANCODE_DOWN]) {
            entity->move(0, 1); // move down
        }
        if (keyState[SDL_SCANCODE_LEFT]) {
            entity->move(-1, 0); // move left
        }
        if (keyState[SDL_SCANCODE_RIGHT]) {
            entity->move(1, 0); // move right
        }

        SDL_RenderClear(renderer); // Clear the current rendering target with the drawing color

        // Render the background
        SDL_Rect backgroundRect;
        backgroundRect.x = 0;
        backgroundRect.y = 0;
        backgroundRect.w = width;
        backgroundRect.h = height;
        SDL_RenderCopy(renderer, texture, NULL, &backgroundRect);

        entity->display(); // Render the sprite to the renderer

        SDL_RenderPresent(renderer); // Update the screen with any rendering performed since the previous call
    }
}