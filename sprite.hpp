// sprite.hpp
#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "entity.hpp"

class Sprite : public Entity {
public:
    Sprite(SDL_Renderer* renderer, const std::string& name, const std::string& image_path, int x, int y, int width, int height);
    Sprite(SDL_Renderer* renderer, int x, int y, int width, int height);
    ~Sprite();

    void display() override;
    std::string& getName() override;
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    bool test_collide(Entity* test, int dx, int dy);
    void move(int dx, int dy) override;
};

#endif // SPRITE_HPP