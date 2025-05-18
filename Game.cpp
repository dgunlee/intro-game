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

    return;
}

void Game::ProcessInput()
{
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