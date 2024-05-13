// sprite.cpp
#include "sprite.hpp"


Sprite::Sprite(SDL_Renderer* renderer, const std::string& name, const std::string& image_path, int x, int y, int width, int height, int frameWidth, int frameHeight, int numFrames, int numColumns)
    : Entity(renderer, name, image_path, x, y, width, height), frameWidth(frameWidth), frameHeight(frameHeight), numFrames(numFrames), numColumns(numColumns), currentFrame(0), frameTime(100), lastFrameTime(0), flipType(SDL_FLIP_NONE) {
    }
Sprite::~Sprite() {
}

void Sprite::display() {
    SDL_Rect srcRect;
    srcRect.x = (currentFrame % numColumns) * frameWidth;
    srcRect.y = (currentFrame / numColumns) * frameHeight;
    srcRect.w = frameWidth;
    srcRect.h = frameHeight;

    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = width;
    dstRect.h = height;

    SDL_RenderCopyEx(renderer, texture, &srcRect, &dstRect, 0, NULL, flipType); // Use SDL_RenderCopyEx and flipType
}

void Sprite::animate(int row, bool flip) {
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime > lastFrameTime + frameTime) {
        currentFrame = (currentFrame + 1) % numFrames;
        lastFrameTime = currentTime;
    }

    SDL_Rect srcRect;
    srcRect.x = (currentFrame % numColumns) * frameWidth;
    srcRect.y = row * frameHeight;
    srcRect.w = frameWidth;
    srcRect.h = frameHeight;

    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = width;
    dstRect.h = height;

    flipType = flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE; // Update flipType
    SDL_RenderCopyEx(renderer, texture, &srcRect, &dstRect, 0, NULL, flipType);
}