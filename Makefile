compile:
	g++ -Wall -std=c++17 -O3 \
	src/*cpp src/engine/core/*cpp \
	src/engine/ecs/*cpp \
	src/engine/ecs/system/*cpp \
	src/engine/gfx/*cpp \
	src/engine/io/*cpp \
	src/engine/math/*cpp \
	src/engine/sfx/*cpp \
	-I/usr/local/sdl2/include \
	-L/usr/local/opt/sdl2/lib \
	-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx -o engine-app
		
	mv -f engine-app build/
	./build/engine-app