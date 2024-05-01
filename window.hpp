// window.hpp
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "entity.hpp"

class Window {
public:
    Window(const std::string& image_path, int width, int height);
    ~Window();
    void display();

private:
    int width, height;
    std::string image_path;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    Entity* entity;
};

#endif // WINDOW_HPP