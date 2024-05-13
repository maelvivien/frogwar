// sprite.hpp
#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "entity.hpp"

class Sprite : public Entity {
public:
    Sprite(SDL_Renderer* renderer, const std::string& name, const std::string& image_path, int x, int y, int width, int height, int frameWidth, int frameHeight, int numFrames, int numColumns);
    virtual ~Sprite();

    virtual void display() override;
    void animate(int row, bool flip = false);

private:
    int frameWidth, frameHeight;
    int numFrames, numColumns;
    int currentFrame;
    Uint32 frameTime, lastFrameTime;
    SDL_RendererFlip flipType; // New member variable to store the flip state
};

#endif // SPRITE_HPP