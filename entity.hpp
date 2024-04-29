// entity.hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Entity {
public:
    Entity(const std::string& name, const std::string& image_path, int x, int y, int vx, int vy);
    virtual ~Entity();

    virtual void move() = 0; // Pure virtual method

    void display(SDL_Renderer* renderer);

    // Getters
    std::string getName() const;
    int getX() const;
    int getY() const;

    // Setters
    void setX(int x);
    void setY(int y);
    void setVX(int vx);
    void setVY(int vy);

protected:
    std::string name;
    SDL_Texture* texture;

    int x, y;   // Position
    int vx, vy; // Velocity
};