#include "Component.h"
#include "Actor.h"

Component::Component(Actor* actor):mActor(actor){
    mActor->AddComponent(this);
}

Component::~Component(){

}

void Component::Update(float deltaTime){

}

void Component::ProcessInput(const Uint8* keyState){

}

Actor* Component::GetActor() const {
    return mActor;
}