#include "Scene.hpp"
#include "Sprite.hpp"

Scene::Scene() {
    this->init();
}

bool Scene::init() {
    bool error = false;
            if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
                cerr << "SDL_Init Error: " << SDL_GetError() << endl;
                error = true;
            }
            
            win = SDL_CreateWindow("SimpleGE in C++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);

            if (!win) {
                cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
                SDL_Quit();
                error = true;
            }

            ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (!ren) {
                cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
                SDL_DestroyWindow(win);
                SDL_Quit();
                error = true;
            }

           // background = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, WINDOW_W, WINDOW_H);

            Sprite sampleSprite = Sprite(ren);
            sampleSprite.dxi = 3;
            sprites.push_back(sampleSprite);

            return error;
        }    

int Scene::mainLoop() {
    bool running = true;
    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    delta = 0;

    while (running) {
        last = now;
        now = SDL_GetPerformanceCounter();
        delta = (double)((now - last)*1000 / (double)SDL_GetPerformanceFrequency()); //ms
        double seconds = delta / 1000.0;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) running = false;
            }
            processEvent(event);
        }

        // small delay to avoid 100% CPU in case vsync is off
        process();
        SDL_Delay(1);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    stop();
    return 0;
}

void Scene::start() {
    keepGoing = true;
    while (keepGoing) {
        mainLoop();
    }
}

void Scene::stop() {
    keepGoing = false;
}

void Scene::processEvent(SDL_Event event) {
    // Event processing code here
}

void Scene::process() {
    /* Happens once per frame, after event parsing.
        Overwrite to add your own code
    */
}

bool Scene::isKeyPressed() {
    // Key press checking code here
    return false;
}