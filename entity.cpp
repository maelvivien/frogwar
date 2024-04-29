// entity.cpp
#include "entity.hpp"

Entity::Entity(const std::string& name, const std::string& image_path, int x, int y, int vx, int vy)
    : name(name), x(x), y(y), vx(vx), vy(vy) {
    SDL_Surface* image = IMG_Load(image_path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
}

Entity::~Entity() {
    SDL_DestroyTexture(texture);
}

void Entity::display(SDL_Renderer* renderer) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

std::string Entity::getName() const { return name; }
int Entity::getX() const { return x; }
int Entity::getY() const { return y; }

void Entity::setX(int x) { this->x = x; }
void Entity::setY(int y) { this->y = y; }
void Entity::setVX(int vx) { this->vx = vx; }
void Entity::setVY(int vy) { this->vy = vy; }