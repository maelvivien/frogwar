// window.hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "player.hpp"

class Window {
public:
    Window(const std::string& image_path, int width, int height);
    ~Window();
    Player player;
    void display();
    SDL_Surface* load_surface(std::string image_path);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;

    int width;
    int height;
    std::string image_path;
};
