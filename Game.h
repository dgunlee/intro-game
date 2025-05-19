#pragma once
#include <SDL.h>
#include <vector>
#include <unordered_map>

class Game {
public:
    Game();
    bool Initialize();
    void Shutdown();
    void RunLoop();

    const int WINDOW_WIDTH = 512;
    const int WINDOW_HEIGHT = 448;
    const int MIN_DELTA = 33;
    const int MAX_DELTA = 16;
    const float MSEC_TO_SEC = 1000.0f;

    // Helpers
    std::vector<class Actor*> GetActors();
    void AddActor(class Actor* actor);
    void RemoveActor(class Actor* actor);

    void AddSprite(class SpriteComponent* sComp);
    void RemoveSprite(class SpriteComponent* sComp);
    SDL_Texture* GetTexture(std::string textureName);

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();
    void LoadData();
    void UnloadData();

    SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
    class Me* me = nullptr;

    bool mGameOver = false;
    Uint32 mCurrentTime = 0;
    std::vector<class Actor*> mActors;
    std::vector<class SpriteComponent*> mSprites;
    std::unordered_map<std::string, SDL_Texture*> mMap;
};