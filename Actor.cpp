#include "Actor.h"
#include "Game.h"
#include "Component.h"

Actor::Actor(Game* game): mGame(game) {
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
}
