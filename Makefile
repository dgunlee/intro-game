CXX = g++
MYDEFS = -g -Wall -std=c++17 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_image
SRC = Actor.cpp AnimatedSprite.cpp Component.cpp Game.cpp Main.cpp Me.cpp MoveComponent.cpp MyMovement.cpp SpriteComponent.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(MYDEFS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(MYDEFS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)