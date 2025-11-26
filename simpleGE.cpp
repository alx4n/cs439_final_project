#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

using namespace std;

#define SQUARE_SIZE 48

class Sprite {
    public:
        Sprite() {
            // Constructor code here
        }

        bool init();
        void addForce();
        bool checkClicked();
        void update();
        void process();
        void setBoundAction();
        void checkBounds();
        void hide();
        void show();
        bool isKeyPressed();
};

class Scene {
    private:
        bool keepGoing = true;

        bool init() {
            bool error = false;
            if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
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

            return error;
        }    

        int mainLoop() {
        //    Sprite sampleSprite = Sprite();
        //    sampleSprite.dx = 3;
        //    sprites.push_back(sampleSprite);
            SDL_Rect player = { WINDOW_W/2 - SQUARE_SIZE/2, WINDOW_H/2 - SQUARE_SIZE/2, SQUARE_SIZE, SQUARE_SIZE };
            const int speed = 300; // pixels per second

            bool running = true;
            Uint64 now = SDL_GetPerformanceCounter();
            Uint64 last = 0;
            double delta = 0;

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

        void stop() {
            keepGoing = false;
        }

    public:
        int WINDOW_W = 800;
        int WINDOW_H = 640;
        SDL_Window *win;
        SDL_Renderer *ren;
        vector<Sprite> sprites;

        Scene() {
            this->init();
        }        

        void start(){
            keepGoing = true;
            while (keepGoing) {
                mainLoop();
            }
        }

        void processEvent(SDL_Event event) {
            // Event processing code here
        }

        void process() {
            /* Happens once per frame, after event parsing.
                Overwrite to add your own code
            */
        }
};



int main(int arc, char *argv[]) {
    Scene scene = Scene();
    scene.start();
    return 0;
}


/*
    
                const Uint8 *ks = SDL_GetKeyboardState(NULL);
                int dx = 0, dy = 0;
                if (ks[SDL_SCANCODE_LEFT] || ks[SDL_SCANCODE_A]) dx = -1;
                if (ks[SDL_SCANCODE_RIGHT] || ks[SDL_SCANCODE_D]) dx = 1;
                if (ks[SDL_SCANCODE_UP] || ks[SDL_SCANCODE_W]) dy = -1;
                if (ks[SDL_SCANCODE_DOWN] || ks[SDL_SCANCODE_S]) dy = 1;

                player.x += (int)(dx * speed * seconds);
                player.y += (int)(dy * speed * seconds);

                // clamp to window
                if (player.x < 0) player.x = 0;
                if (player.y < 0) player.y = 0;
                if (player.x + player.w > WINDOW_W) player.x = WINDOW_W - player.w;
                if (player.y + player.h > WINDOW_H) player.y = WINDOW_H - player.h;

                // render
                SDL_SetRenderDrawColor(ren, 30, 30, 40, 255);
                SDL_RenderClear(ren);

                // draw player
                SDL_SetRenderDrawColor(ren, 220, 80, 60, 255);
                SDL_RenderFillRect(ren, &player);

                SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
                SDL_Rect border = {10, 10, WINDOW_W - 20, WINDOW_H - 20};
                SDL_RenderDrawRect(ren, &border);

                SDL_RenderPresent(ren);

*/