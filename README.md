# simpleGEC
A port of Andy Harris's simpleGE Python game engine to C++ using SDL as a graphics framework.

## Build Instructions
Build and run (Ubuntu / Debian):
1. Install dependencies:
```
sudo apt update
sudo apt install -y build-essential libsdl2-dev pkg-config
```
2. Run
`make run`

## Overview
This is a game engine designed to be simple to use for the beginner programmer who wants to delve into C++ game programming. It is made up of two primary classes: the Scene and the Sprite.

### The Scene
One of two primary classes in simpleGEC is the Scene class. It creates a window and renderer for you to create and draw to a window. It can be used as-is or subclassed for custom scenes.

### The Sprite
The other of the two primary classes is the Sprite class. This class allows you to use textures as well as bounding-rectangles to create sprites. It can also be subclassed for customization.

# Documentation
## Scene
### Constructor
Scene myScene = Scene();
### Properties
- win - the SDL_Window with a display surface
- ren - the SDL_Renderer which allows you to draw to the screen
- sprites - a vector of Sprite pointers, to which all sprites must be added

### Methods
- void start() - begins the main loop of the scene
- void stop() - ends the main loop
- void mainLoop() - executes once per millisecond and calls the Sprites' main loop as well as the Scene's drawToScreen method
- void processEvent(event) - is called once for every event, meant to be overwritten
- void process() - is called once per frame, meant to be overwritten
- setBackgroundColor(r, g, b, a) - changes the color being rendered to the background
- drawToScreen() - draws background and sprites to screen once per frame

## Sprite
### Constructor
Sprite mySprite = Sprite(scene, scene->ren);

### Properties
- ren - the SDL_Renderer
- spriteRect - a rectangle used as the bounding rectangle of the sprite
- x - the x position of the center of the sprite
- y - the y position of the center of the sprite
- dxi - integer change of x in every frame
- dyi - integer change of y in every frame
- speed - indicates how many pixels a sprite moves per frame

### Methods
- init()
- mainLoop()
- update()
- process()
- draw()
