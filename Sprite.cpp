#include "Sprite.hpp"
#include "Scene.hpp"

using namespace std;

Sprite::Sprite(Scene *scene, SDL_Renderer *ren) {
    this->ren = ren;
    this->scene = scene;
}

bool Sprite::init() {
    bool error = false;

    player = { WINDOW_W/2 - SQUARE_SIZE/2, WINDOW_H/2 - SQUARE_SIZE/2, SQUARE_SIZE, SQUARE_SIZE };
    speed = 300; // pixels per second


    return error;
}

void Sprite::draw() {
    // draw player
    SDL_SetRenderDrawColor(ren, 220, 80, 60, 255);
    SDL_RenderFillRect(ren, &player);
}

void Sprite::update() {
    ks = SDL_GetKeyboardState(NULL);
    if (ks[SDL_SCANCODE_LEFT] || ks[SDL_SCANCODE_A]) dxi = -1;
    if (ks[SDL_SCANCODE_RIGHT] || ks[SDL_SCANCODE_D]) dxi = 1;
    if (ks[SDL_SCANCODE_UP] || ks[SDL_SCANCODE_W]) dyi = -1;
    if (ks[SDL_SCANCODE_DOWN] || ks[SDL_SCANCODE_S]) dyi = 1;

    player.x += (int)(dxi * speed * scene->delta);
    player.y += (int)(dyi * speed * scene->delta);

    // clamp to window
    if (player.x < 0) player.x = 0;
    if (player.y < 0) player.y = 0;
    if (player.x + player.w > WINDOW_W) player.x = WINDOW_W - player.w;
    if (player.y + player.h > WINDOW_H) player.y = WINDOW_H - player.h;

    

    

    SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
    SDL_Rect border = {10, 10, WINDOW_W - 20, WINDOW_H - 20};
    SDL_RenderDrawRect(ren, &border);

    SDL_RenderPresent(ren);
}