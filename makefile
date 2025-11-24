game: simpleGE.cpp
	g++ simpleGE.cpp $(shell pkg-config --cflags --libs sdl2) -o game

clean:
	rm game

run: game
	./game