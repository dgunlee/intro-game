#include "Game.h"
#include "SpriteComponent.h"
#include "SDL_image.h"
#include "Actor.h"
#include "Me.h"
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

    IMG_Init(IMG_INIT_PNG);
    
    std::cout << "Loading" << std::endl;
    LoadData();
    std::cout << "Finished Loading" << std::endl;
	return mRenderer != nullptr;
}

void Game::Shutdown()
{
    IMG_Quit();
    UnloadData();
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

    std::vector<Actor*> actors = mActors;
    for (size_t i = 0; i < actors.size(); i++){
        actors[i]->ProcessInput(keys);
    }

    if (keys[SDL_SCANCODE_ESCAPE]){
        mGameOver = !mGameOver;
    }
}

void Game::UpdateGame()
{
    int deltaTime = SDL_GetTicks() - mCurrentTime;

    while (deltaTime < MIN_DELTA){
        deltaTime = SDL_GetTicks() - mCurrentTime;
    }

    if (deltaTime > MAX_DELTA){
        deltaTime = MAX_DELTA;
    }
    mCurrentTime += deltaTime;

    float deltaInSeconds = deltaTime / MSEC_TO_SEC;
    
    std::vector<Actor*> actors = mActors;
    std::vector<Actor*> temp;

    for (size_t i = 0; i < actors.size(); i++){
        actors[i]->Update(deltaInSeconds);
    }
}


void Game::GenerateOutput()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);

    for (auto i : mSprites){
        if (i->IsVisible()){
            i->Draw(mRenderer);
        }
    }
    SDL_RenderPresent(mRenderer);
}

void Game::LoadData(){
    Actor* background = new Actor(this);
    background->SetPosition(WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f);
    background->SetScale(0.30f);
    SpriteComponent* backgroundSprite = new SpriteComponent(background);
    backgroundSprite->SetTexture(GetTexture("assets/background/bg2.png"));

    me = new Me(this);
    me->SetPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
}

void Game::UnloadData(){
    while (!mActors.empty()){
        delete mActors.back();
    }
    for (auto it = mMap.begin(); it != mMap.end(); ++it){
        SDL_DestroyTexture(it->second);
    }
    mMap.clear();
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

void Game::AddSprite(class SpriteComponent* sComp)
{
	mSprites.emplace_back(sComp);
	std::sort(mSprites.begin(), mSprites.end(), [](SpriteComponent* a, SpriteComponent* b) {
		return a->GetDrawOrder() < b->GetDrawOrder();
	});
}

void Game::RemoveSprite(class SpriteComponent* sComp)
{
	auto it = std::find(mSprites.begin(), mSprites.end(), sComp);
	if (it != mSprites.end())
	{
		mSprites.erase(it);
	}
}

SDL_Texture* Game::GetTexture(std::string textureName)
{
	if (mMap.find(textureName) != mMap.end())
	{
		return mMap[textureName];
	}
	const char* textureNameInChar = textureName.c_str();
	SDL_Surface* surface = IMG_Load(textureNameInChar);
	if (surface == nullptr)
	{
		SDL_Log("%s failed to load", textureName.c_str());
	}
	else
	{
		SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, surface);
		SDL_FreeSurface(surface);
		mMap[textureName] = texture;
		return texture;
	}
	return nullptr;
}