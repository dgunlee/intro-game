#pragma once
#include <SDL.h>

class Game {

public:
    Game();
    bool Initialize();
    void Shutdown();
    void RunLoop();
private:

    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    const int WINDOW_WIDTH = 1024;
    const int WINDOW_HEIGHT = 768;

    SDL_Window* mWindow;
	SDL_Renderer* mRenderer;


};