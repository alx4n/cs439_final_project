#ifndef Scene_hpp
#define Scene_hpp

#include <SDL2/SDL.h>
#include <iostream>
#include "Sprite.hpp"
#include <vector>

#define SQUARE_SIZE 48
#define WINDOW_W 800
#define WINDOW_H 640

using namespace std;

class Sprite;

class Scene {
    private:
        bool keepGoing = true;
        double delta;
       // SDL_Texture background = SDL_Texture * SDL_CreateTexture(SDL_Renderer *ren, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, WINDOW_W, WINDOW_H);

        bool init();
        void stop();

    public:
    //    int WINDOW_W = 800;
      //  int WINDOW_H = 640;
        SDL_Window *win;
        SDL_Renderer *ren;
        vector<Sprite> sprites;

        Scene();     
        void start();
        int mainLoop();
        void processEvent(SDL_Event event);
        void process();
        bool isKeyPressed();
};

#endif