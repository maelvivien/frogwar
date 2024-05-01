// sprite.hpp
#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "entity.hpp"

class Sprite : public Entity {
public:
    Sprite(SDL_Renderer* renderer, const std::string& name, const std::string& image_path, int x, int y, int width, int height);
    virtual ~Sprite();

    virtual void display() override;
};

#endif // SPRITE_HPP