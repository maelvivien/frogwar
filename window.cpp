// window.cpp
#include "window.hpp"
#include "player.hpp"

Window::Window(const std::string& image_path, int width, int height)
    : width(width), height(height), image_path(image_path), player("Player", "plante.png", 0, 0, 0, 0) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    window = SDL_CreateWindow("Display Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface* image = load_surface(image_path);
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
}

Window::~Window() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}
void Window::display() {
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }// window.cpp

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        running=false;
                        break;                    case SDLK_UP:
                        player.setY(player.getY() - 1);
                        break;
                    case SDLK_DOWN:
                        player.setY(player.getY() + 1);
                        break;
                    case SDLK_LEFT:
                        player.setX(player.getX() - 1);
                        break;
                    case SDLK_RIGHT:
                        player.setX(player.getX() + 1);
                        break;
            }
            }
        }

        SDL_RenderClear(renderer);
        player.display(renderer);
        SDL_RenderPresent(renderer);
    }
}

SDL_Surface* Window::load_surface(std::string image_path){
    SDL_Surface* image = IMG_Load(image_path.c_str());
    return image;
}

  
