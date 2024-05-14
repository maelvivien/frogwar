// window.cpp
#include "window.hpp"

Window::Window(const std::string& image_path, int width, int height)
    : width(width), height(height), image_path(image_path) {

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_VIDEO) < 0) {
        printf("Error initializing the process\n");
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ){
        printf("Audio could not be initialized\n");
    }

    window = SDL_CreateWindow("Window Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        // handle error
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        // handle error
    } 
    entity = new Sprite(renderer, "test1", "texture/perso.png", 450, 350, 200, 300);
    player2 = new Sprite (renderer, "player2", "texture/perso2.png", 800, 100, 300, 300);
    entityvector.push_back(entity);
    entityvector.push_back(player2);
    window_init();
}

void Window::window_init(){
    SDL_Surface* image = IMG_Load(image_path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    collisionvector.clear();
    
    if (image_path == "texture/background.png") {
        Sprite* collision = new Sprite(renderer, 400, 300, 200, 20);
        collisionvector.push_back(collision);
        collision = new Sprite(renderer, 0, 900, 1920, 120);
        collisionvector.push_back(collision);
        collision = new Sprite(renderer, 925, 775, 150, 220);
        collisionvector.push_back(collision);
        collision = new Sprite(renderer, 1075, 535, 220, 620);
        collisionvector.push_back(collision);
        collision = new Sprite(renderer, 1295, 655, 140, 220);
        collisionvector.push_back(collision);
        collision = new Sprite(renderer, 1630, 0, 320, 185);
        collisionvector.push_back(collision);
        collision = new Sprite(renderer, 1900, 150, 120, 150);
        collisionvector.push_back(collision);
        gMusic = Mix_LoadMUS( "sound/music.ogg");
    }
    if (image_path == "texture/background2.png") {
        gMusic = Mix_LoadMUS( "sound/music2.ogg");
    }
    Mix_PlayMusic( gMusic, -1 );
    
}

Window::~Window() {
    delete entity;
    for (long unsigned int i = 0; i < collisionvector.size(); i++){
        delete collisionvector[i];
    }
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Window::display() {
    bool running = true;
    SDL_Event event;

    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        if (keyState[SDL_SCANCODE_UP]) {
            bool state = true;
            for (long unsigned int i = 0; i < collisionvector.size(); i++){
                if (entity->test_collide(collisionvector[i], 0, -1)) state = false;
            }
            if (state) entity->move(0,-1); // move up
        }
        if (keyState[SDL_SCANCODE_DOWN]) {
            bool state = true;
            for (long unsigned int i = 0; i < collisionvector.size(); i++){
                if (entity->test_collide(collisionvector[i], 0, 1)) state = false;
            }
            if (state) entity->move(0,1); // move down
        }
        if (keyState[SDL_SCANCODE_LEFT]) {
            bool state = true;
            for (long unsigned int i = 0; i < collisionvector.size(); i++){
                if (entity->test_collide(collisionvector[i], -1, 0)) state = false;
            }
            if (state) entity->move(-1, 0); // move left
        }
        if (keyState[SDL_SCANCODE_RIGHT]) {
            bool state = true;
            for (long unsigned int i = 0; i < collisionvector.size(); i++){
                if (entity->test_collide(collisionvector[i], 1, 0)) state = false;
            }
            if (state) entity->move(1,0); // move right
        }

        ///////////////////////////////////////////////////////////////////////////

        if (keyState[SDL_SCANCODE_I]) {
            bool state = true;
            for (long unsigned int i = 0; i < collisionvector.size(); i++){
                if (player2->test_collide(collisionvector[i], 0, -1)) state = false;
            }
            if (state) player2->move(0,-1); // move up
        }
        if (keyState[SDL_SCANCODE_K]) {
            bool state = true;
            for (long unsigned int i = 0; i < collisionvector.size(); i++){
                if (player2->test_collide(collisionvector[i], 0, 1)) state = false;
            }
            if (state) player2->move(0,1); // move down
        }
        if (keyState[SDL_SCANCODE_J]) {
            bool state = true;
            for (long unsigned int i = 0; i < collisionvector.size(); i++){
                if (player2->test_collide(collisionvector[i], -1, 0)) state = false;
            }
            if (state) player2->move(-1, 0); // move left
        }
        if (keyState[SDL_SCANCODE_L]) {
            bool state = true;
            for (long unsigned int i = 0; i < collisionvector.size(); i++){
                if (player2->test_collide(collisionvector[i], 1, 0)) state = false;
            }
            if (state) player2->move(1,0); // move right
        }

        /////////////////////////////////////////////////////////////////////////////////


        if (keyState[SDL_SCANCODE_Q]) {
            if (1 != 1) { // Turned toward the right side of the screen
                for (long unsigned int i = 0; i < entityvector.size(); i++) {
                    if (entityvector[i]->getName() != entity->getName()){
                        if (entity->test_collide(entityvector[i], 50, 0)){
                            printf("collision\n");
                        }
                        else {
                            printf("miss\n");
                        }
                    }
                }
            }
            else {
                for (long unsigned int i = 0; i < entityvector.size(); i++) {
                    if (entityvector[i]->getName() != entity->getName()){
                        if (entity->test_collide(entityvector[i], -50, 0)){
                            printf("collision\n");
                        }
                        else {
                            printf("miss\n");
                        }
                    }
                }
            }
        }
        if (keyState[SDL_SCANCODE_W]) {
            image_path = "texture/background.png";
            window_init();
        }

        SDL_RenderClear(renderer); // Clear the current rendering target with the drawing color

        // Render the background
        SDL_Rect backgroundRect;
        backgroundRect.x = 0;
        backgroundRect.y = 0;
        backgroundRect.w = width;
        backgroundRect.h = height;
        SDL_RenderCopy(renderer, texture, NULL, &backgroundRect);

        entity->display(); // Render the sprite to the renderer
        player2->display();

        SDL_RenderPresent(renderer); // Update the screen with any rendering performed since the previous call
    }
}

