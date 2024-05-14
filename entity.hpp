// entity.hpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Entity {
public:
    virtual ~Entity();

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
    int gravity = 7 ,yspeed = 0,xspeed = 0,MAX_XSPEED = 1;
    float jumpTime = 0.0f; // New variable to track jump time
    float maxJumpTime = 1; // Maximum allowed jump time
    float frottement = 1;
    int signe = 0;
};

#endif // ENTITY_HPP