#include "entity.hpp"

class Enemy : public Entity{
    public:
        Enemy(const std::string& name, const std::string& image_path, int x, int y, int vx, int vy, int hp);
        void move_hori();
        void move_vert();
    private:
        std::string name;
        SDL_Texture* texture;
        int x;
        int y;
        int vx;
        int vy;
        int hp;
};