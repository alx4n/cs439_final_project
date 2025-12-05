#include "Scene.hpp"
#include "Sprite.hpp"

#define IMG_FLAGS (IMG_INIT_PNG | IMG_INIT_JPG)

Scene::Scene() {
    this->init();
}

bool Scene::init() {
    bool error = false;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cerr << "SDL_Init Error: " << SDL_GetError() << endl;
        error = true;
    }
    if ((IMG_Init(IMG_FLAGS) & IMG_FLAGS) != IMG_FLAGS) {
        cerr << "IMG_Init Error: " << IMG_GetError() << endl;
    }
    
    win = SDL_CreateWindow("SimpleGEC", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);

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

    sampleSprite = new Sprite(this, ren);
    sampleSprite->dxi = 3;
    sprites.push_back(sampleSprite);

    // render background
    setBackgroundColor(30, 30, 40, 255);
//    if (imageFileName != "") {
  //      loadBackgroundImage(imageFileName);
    //} else {
      //  setBackgroundColor(255, 255, 0, 255);
//    }

    return error;
}    

void Scene::mainLoop() {
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
    //    sampleSprite->update();
        drawToScreen();

        process();
        

        // small delay to avoid 100% CPU in case vsync is off
        SDL_Delay(1);
    }

   // delete(sampleSprite);
    SDL_DestroyTexture(background);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
    stop();
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

void Scene::setBackgroundColor(int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(ren, r, g, b, a);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
}

void Scene::loadBackgroundImage(const char *fileName) {
    background = IMG_LoadTexture(ren, fileName);
    if (!background) {
        cerr << "SDL_Texture Error: " << IMG_GetError() << endl;
    }
}

void Scene::drawToScreen() {
    

//    SDL_SetRenderDrawColor(ren, 30, 30, 40, 255);
  //  SDL_RenderClear(ren);
    //SDL_RenderPresent(ren);
  //  setBackgroundColor(30, 30, 40, 255);
//    SDL_RenderClear(ren);
   // SDL_RenderCopy(ren, background, NULL, NULL);
 //   sampleSprite->mainLoop();
    sampleSprite->draw();
   // for (Sprite sprite : sprites) {
     //   sprite.draw();
       // cout << "Sprite drawn" << endl;
    //}
 //   sampleSprite->draw();
  //  SDL_RenderDrawRect(ren, sampleSprite->spriteRect);
    
   SDL_RenderPresent(ren);
}