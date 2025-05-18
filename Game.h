#pragma once
#include <SDL.h>
#include <vector>

class Game {
public:
    Game();
    bool Initialize();
    void Shutdown();
    void RunLoop();

    const int WINDOW_WIDTH = 1024;
    const int WINDOW_HEIGHT = 768;

    // Getters
    std::vector<class Actor*> GetActors();
    void AddActor(class Actor* actor);
    void RemoveActor(class Actor* actor);

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
    bool mGameOver = false;
    std::vector<class Actor*> mActors;
};