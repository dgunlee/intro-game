#include "Actor.h"
#include "Game.h"
#include "Component.h"

Actor::Actor(Game* game): mGame(game), mScale(1.0f) {
    mGame->AddActor(this);
}

Actor::~Actor(){
    mGame->RemoveActor(this);
    for (size_t i = 0; i < mComponents.size(); i++){
        delete mComponents[i];
    }
    mComponents.clear();
}

void Actor::Update(float deltaTime){
    for (size_t i = 0; i < mComponents.size(); i++){
        mComponents[i]->Update(deltaTime);
    }
    OnUpdate(deltaTime);
}

void Actor::OnUpdate(float deltaTime){

}

void Actor::ProcessInput(const Uint8* keyState){
    for (size_t i = 0; i < mComponents.size(); i++){
        mComponents[i]->ProcessInput(keyState);
    }
    OnProcessInput(keyState);
}

void Actor::AddComponent(Component* c){
    mComponents.emplace_back(c);
    std::sort(mComponents.begin(), mComponents.end(), [](Component* a, Component* b) {
		return a->GetUpdateOrder() < b->GetUpdateOrder();
	});
}

void Actor::SetPosition(float x, float y){
    pos.SetPosition(x, y);
}

void Actor::SetPosition(int x, int y){
    pos.SetPosition(x*1.0, y*1.0);
}

Game* Actor::GetGame(){
    return mGame;
}

Position Actor::GetPosition(){
    return pos;
}

void Actor::OnProcessInput(const Uint8* keyState){

}