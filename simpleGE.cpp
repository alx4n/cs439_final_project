#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <tuple>
#include "Sprite.hpp"
#include "Scene.hpp"

using namespace std;

int main(int arc, char *argv[]) {
    Scene *scene = new Scene();
    scene->start();
    Sprite rect = Sprite(scene, scene->ren);
    return 0;
}