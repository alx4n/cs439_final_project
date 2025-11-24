#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

const int WIDTH = 800, HEIGHT = 600;

int main(int arc, char *argv[]) {
    cout << "Hello World!!" << endl;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 640, SDL_WINDOW_ALLOW_HIGHDPI);


    if (NULL == window) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Event windowEvent;

    bool running = true;

    while (running) {
        if (SDL_PollEvent (&windowEvent)) {
            if (SDL_QUIT == windowEvent.type) {
                running = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}