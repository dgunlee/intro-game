CXX = g++
MYDEFS = -g -Wall -std=c++17 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`
SRC = Main.cpp Game.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(MYDEFS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(MYDEFS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)