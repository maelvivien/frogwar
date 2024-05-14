// sprite.cpp
#include "sprite.hpp"

Sprite::Sprite(SDL_Renderer* renderer, const std::string& name, const std::string& image_path, int x, int y, int width, int height){
    _renderer = renderer;
    _name = name;
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    
    SDL_Surface* image = IMG_Load(image_path.c_str());
    _texture = SDL_CreateTextureFromSurface(_renderer, image);
    SDL_FreeSurface(image);
}

Sprite::Sprite(SDL_Renderer* renderer, int x, int y, int width, int height) {
    _renderer = renderer;
    _name = "";
    _x = x;
    _y = y;
    _width = width;
    _height = height;

}


Sprite::~Sprite() {
    SDL_DestroyTexture(_texture);

}

void Sprite::display() {
    SDL_Rect rect;
    rect.x = _x;
    rect.y = _y;
    rect.w = _width;
    rect.h = _height;
    SDL_RenderCopy(_renderer, _texture, NULL, &rect);
}

/*
void Entity::display() {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}*/

void Sprite::move(int dx, int dy) {
    _x += dx;
    _y += dy;
}

std::string& Sprite::getName(){
    return _name;
}

int Sprite::getX() {
    return _x;
}

int Sprite::getY() {
    return _y;
}

int Sprite::getHeight() {
    return _height;
}

int Sprite::getWidth() {
    return _width;
}

bool Sprite::test_collide(Entity* test, int dx, int dy){
    if ((getX() + getWidth() + dx > test->getX() && getX() + dx < test->getX() + test->getWidth())
        && (getY() + getHeight() + dy > test->getY() && getY() + dy < test->getY() + test->getHeight())) return true;
    return false;
}