#include "Sprite.hpp"
#include "Scene.hpp"

using namespace std;

Sprite::Sprite(Scene *scene, SDL_Renderer *ren) {
    this->scene = scene;
    this->ren = ren;
}

bool Sprite::init() {
    bool error = false;

    /*
    this->spriteRect->x = 100;
    this->spriteRect->y = 100;
    this->spriteRect->w = SQUARE_SIZE;
    this->spriteRect->h = SQUARE_SIZE;
  */
//    spriteSurf = IMG_Load("images.venmoCode.png");
  //  if (!spriteSurf) {
    //    cerr << "IMG_Load Error: " << IMG_GetError() << endl;
      //  error = true;
  //  }
    speed = 300; // pixels per second
 //   SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 220, 80, 60, 255);
    SDL_RenderFillRect(ren, &spriteRect);
    SDL_RenderPresent(ren);

    return error;
}

void Sprite::mainLoop() {
    update();
    process();
    draw();
}

void Sprite::draw() {
    // draw player
    //SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 220, 80, 60, 255);
    SDL_RenderFillRect(ren, &spriteRect);
   // SDL_RenderPresent(ren);
  //  SDL_RenderCopy(ren, spriteRect, NULL, NULL);
}

void Sprite::process() {

}

void Sprite::update() {
    ks = SDL_GetKeyboardState(NULL);
    if (ks[SDL_SCANCODE_LEFT] || ks[SDL_SCANCODE_A]) dxi = -1;
    if (ks[SDL_SCANCODE_RIGHT] || ks[SDL_SCANCODE_D]) dxi = 1;
    if (ks[SDL_SCANCODE_UP] || ks[SDL_SCANCODE_W]) dyi = -1;
    if (ks[SDL_SCANCODE_DOWN] || ks[SDL_SCANCODE_S]) dyi = 1;

    spriteRect.x += (int)(dxi * speed * scene->delta);
    spriteRect.y += (int)(dyi * speed * scene->delta);

    // clamp to window
    if (spriteRect.x < 0) spriteRect.x = 0;
    if (spriteRect.y < 0) spriteRect.y = 0;
    if (spriteRect.x + spriteRect.w > WINDOW_W) spriteRect.x = WINDOW_W - spriteRect.w;
    if (spriteRect.y + spriteRect.h > WINDOW_H) spriteRect.y = WINDOW_H - spriteRect.h;
    
    draw();
    
//    SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
  //  SDL_Rect border = {10, 10, WINDOW_W - 20, WINDOW_H - 20};
    //SDL_RenderDrawRect(ren, &border);

    SDL_RenderPresent(ren);
}