#include "Game.h"
#include <iostream>

Game::Game()
: mWindow(nullptr)
, mRenderer(nullptr)
{
}
bool Game::Initialize()
{

    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0){
        return false;
    }

	mWindow = SDL_CreateWindow("DG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (mWindow == nullptr)
	{
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1,
								   SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	return mRenderer != nullptr;
}

void Game::Shutdown()
{
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::RunLoop()
{
    while (!mGameOver){
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
    return;
}

void Game::ProcessInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            mGameOver = !mGameOver;
        }
    }

    const Uint8* keys = SDL_GetKeyboardState(NULL);

    return;
}

void Game::UpdateGame()
{
    return;
}

void Game::GenerateOutput()
{
    return;
}

std::vector<Actor*> Game::GetActors(){
    return mActors;
}

void Game::AddActor(Actor* actor){
    mActors.emplace_back(actor);
}

void Game::RemoveActor(Actor* actor){
    auto it = std::find(mActors.begin(), mActors.end(), actor);
    if (it != mActors.end()){
        mActors.erase(it);
    }
}