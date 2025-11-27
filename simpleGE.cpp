#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <tuple>
#include "Sprite.hpp"
#include "Scene.hpp"

using namespace std;

#define SQUARE_SIZE 48
#define WINDOW_W 800
#define WINDOW_H 640

int main(int arc, char *argv[]) {
    Scene scene = Scene();
    scene.start();
    return 0;
}