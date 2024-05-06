// entity.cpp
#include "entity.hpp"

Entity::Entity(SDL_Renderer* renderer, const std::string& name, const std::string& image_path, int x, int y, int width, int height)
    : renderer(renderer), name(name), x(x), y(y), width(width), height(height) {
    SDL_Surface* image = IMG_Load(image_path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
}

Entity::~Entity() {
    SDL_DestroyTexture(texture);
}

void Entity::display() {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Entity::move(int dx, int dy) {
    x += dx;
    if(x + dx < 0) x=0;
    if(x + dx > 1920-width) x=1920-width;

    y = y - gravity;
    y += dy;
    if(y + dy < 0) y=0;
    if(y>1080-height)y=1080-height;
} 