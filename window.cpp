// window.cpp
#include "window.hpp"
#include "sprite.hpp"
#include <chrono>
#include <thread>

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

    //entity = new Sprite(renderer, "test1", "texture/frog2.png", 100, 100, 300, 250, 150, 150, 10, 10);
    entity = new Sprite(renderer, "test1", "texture/frogknight3.png", 100, 100, 300, 250, 100, 100, 16, 16);
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
    bool flip = false;
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
            flip = true;
        }
        if (keyState[SDL_SCANCODE_RIGHT]) {
            entity->move(1, 0); // move right
            flip = false;
        }
        entity->move(0, 0); // actualisation of the entity

        SDL_RenderClear(renderer); // Clear the current rendering target with the drawing color

        // Render the background
        SDL_Rect backgroundRect;
        backgroundRect.x = 0;
        backgroundRect.y = 0;
        backgroundRect.w = width;
        backgroundRect.h = height;
        SDL_RenderCopy(renderer, texture, NULL, &backgroundRect);

        // Animate and display the sprite
        Sprite* sprite = dynamic_cast<Sprite*>(entity);
        if (sprite != nullptr) {
            sprite->animate(0, flip); // Animate the first row of the sprite sheet
            entity->display(); // Render the sprite to the renderer
        }

        SDL_RenderPresent(renderer); // Update the screen with any rendering performed since the previous call
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}