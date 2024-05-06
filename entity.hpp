// entity.hpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Entity {
public:
    Entity(SDL_Renderer* renderer, const std::string& name, const std::string& image_path, int x, int y, int width, int height);
    Entity(SDL_Renderer* renderer, int x, int y, int width, int height);
    virtual ~Entity();

    virtual void display() = 0; // Pure virtual function
    void move(int dx, int dy); // Declaration of the move function
    int getX();
    int getY();
    int getWidth();
    int getHeight();

protected:
    std::string name;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    int x, y, width, height;
};

#endif // ENTITY_HPP