#include "Component.h"
#include "Actor.h"
#include "Game.h"

Component::Component(Actor* actor, int updateOrder):mOwner(actor), mUpdateOrder(updateOrder){
    mOwner->AddComponent(this);
}

Component::~Component(){

}

void Component::Update(float deltaTime){

}

void Component::ProcessInput(const Uint8* keyState){

}

Actor* Component::GetActor() const {
    return mOwner;
}

Game*  Component::GetGame() const {
    return mOwner->GetGame();
}