// player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"

class Player : public Entity {
public:
    Player(SDL_Renderer* renderer, const std::string& name, const std::string& image_path, const std::string& image_path, int x, int y, int width, int height);
    Player(SDL_Renderer* renderer, int x, int y, int width, int height);
    virtual ~Player();

    virtual void display() override;
    void move(int dx, int dy);
    virtual std::string& getName() override;
};

#endif // PLAYER_HPP