// player.cpp
#include "player.hpp"

Player::Player(SDL_Renderer* renderer, const std::string& name, const std::string& image_path, int x, int y, int width, int height)
    : Entity(renderer, name, image_path, x, y, width, height) {
}

Player::Player(SDL_Renderer* renderer, int x, int y, int width, int height)
    : Entity(renderer, x, y, width, height) {
}


Player::~Player() {
}

void Player::display() {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

std::string& Player::getName(){
    return name;
}