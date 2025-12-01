game: simpleGE.cpp Scene.cpp Sprite.cpp
	g++ -std=c++17 simpleGE.cpp Scene.cpp Sprite.cpp $(shell pkg-config --cflags --libs sdl2) -lSDL2_image -o game

clean:
	rm game

run: game
	./game