#ifndef Scene_hpp
#define Scene_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Sprite.hpp"
#include <vector>

#define SQUARE_SIZE 48
#define WINDOW_W 800
#define WINDOW_H 640

using namespace std;

struct SDL_Texture;

class Sprite;

class Scene {
    private:
        bool keepGoing = true;
       // SDL_Texture background = SDL_Texture * SDL_CreateTexture(SDL_Renderer *ren, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, WINDOW_W, WINDOW_H);

        bool init();
        void stop();

    public:
    //    int WINDOW_W = 800;
      //  int WINDOW_H = 640;
        SDL_Window *win;
        SDL_Renderer *ren;
        SDL_Texture *background;
        const char *imageFileName = "images/lakes.jpg";
        vector<Sprite*> sprites;
        Sprite *sampleSprite;
        double delta;

        Scene();
        void start();
        void mainLoop();
        void processEvent(SDL_Event event);
        void process();
        bool isKeyPressed();
        void setBackgroundColor(int r, int g, int b, int a);
        void loadBackgroundImage(const char *fileName);
        void drawToScreen();
};

#endif