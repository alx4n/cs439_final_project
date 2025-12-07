#ifndef Sprite_hpp
#define Sprite_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <tuple>
#include "Scene.hpp"

#define SQUARE_SIZE 48
#define WINDOW_W 800
#define WINDOW_H 640

using namespace std;

class Scene;

class Sprite {
    private:
        double dxf = 0.0;
        double dyf = 0.0;
        double moveAngle = 0.0;
        double imageAngle = 0.0;

        SDL_Renderer *ren;

    public:
        enum BoundAction {
            WRAP,
            BOUNCE,
            STOP,
            HIDE,
            CONTINUE
        };
        
        Sprite(Scene *scene, SDL_Renderer *ren);

        tuple<int, int> position;
        BoundAction boundAction = WRAP;
        SDL_Rect spriteRect;
    //    SDL_Surface *spriteSurf;
    //    SDL_Texture image;
        int x = 100;
        int y = 100;
        int dxi = 0;
        int dyi = 0;
        int speed = 0;
        bool visible = true;
        bool clicked = false;
        bool mouseOver = false;
        bool mouseDown = false;
        const Uint8 *ks;
        Scene *scene;

        void init();
        void addForce();
        bool checkClicked();
        void mainLoop();
        void update();
        void process();
        void draw();
        void setBoundAction();
        void checkBounds();
        void hide();
        void show();
        bool isKeyPressed();
};

#endif