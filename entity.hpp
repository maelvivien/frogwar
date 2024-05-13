// entity.hpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Entity {
public:
    Entity(SDL_Renderer* renderer, const std::string& name, const std::string& image_path, int x, int y, int width, int height);
    virtual ~Entity();

    virtual void display() = 0; // Pure virtual function
    void move(int dx, int dy); // Declaration of the move function

protected:
    std::string name;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    int x, y, width, height;
    int gravity = 7 ,yspeed = 0,xspeed = 0,MAX_XSPEED = 10;
    float jumpTime = 0.0f; // New variable to track jump time
    float maxJumpTime = 1; // Maximum allowed jump time
    float frottement = 1;
    int signe = 0;

};

#endif // ENTITY_HPP