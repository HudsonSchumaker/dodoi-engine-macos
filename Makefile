# Define compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -O3 -I/usr/local/opt/sdl2/include
LDFLAGS = -L/usr/local/opt/sdl2/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx

# Define source files and output
SRC = src/*.cpp src/game/*.cpp src/engine/core/*.cpp src/engine/ecs/*.cpp src/engine/ecs/system/*.cpp src/engine/gfx/*.cpp src/engine/io/*.cpp src/engine/math/*.cpp src/engine/sfx/*.cpp
OUTPUT = build/engine-app

# Target to create precompiled header
pch:
	$(CXX) -x c++-header -c $(CXXFLAGS) ./src/Pch.h -o ./build/pch.h.gch

# Target to compile the project
compile:
	$(CXX) $(CXXFLAGS) -include-pch ./build/pch.h.gch $(SRC) $(LDFLAGS) -o $(OUTPUT)

# Target to run the application
run: compile
	./$(OUTPUT)

# Default target
all: run