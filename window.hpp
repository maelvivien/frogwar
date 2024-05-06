// window.hpp
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "sprite.hpp"
#include <vector>

class Window {
public:
    Window(const std::string& image_path, int width, int height);
    void window_init();
    ~Window();
    void display();
    bool test_collide(Entity* entity, Entity* test, int dx, int dy);
    

private:
    int width, height;
    std::string image_path;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    Entity* entity;
    Entity* player2;
    std::vector<Sprite*> collisionvector;
};

#endif // WINDOW_HPP