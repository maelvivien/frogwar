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
    float gravity = 1.0 ,yspeed = 0.0f,xspeed = 0.0f;
    float jumpTime = 0.0f; // New variable to track jump time
    float maxJumpTime = 0.5f; // Maximum allowed jump time
    int frottement = 1,MAX_XSPEED = 1;
    

};

#endif // ENTITY_HPP