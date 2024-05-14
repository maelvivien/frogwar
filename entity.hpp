// entity.hpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Entity {
public:

    virtual ~Entity() {};

    virtual void display() = 0; // Pure virtual function
    virtual void move(int dx, int dy) = 0; // Declaration of the move function
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual std::string& getName();

protected:
    std::string _name;
    SDL_Texture* _texture;
    SDL_Renderer* _renderer;
    int _x, _y, _width, _height;
};

#endif // ENTITY_HPP