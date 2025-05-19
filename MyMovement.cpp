#include "MyMovement.h"
#include "Actor.h"
#include "Me.h"
#include "AnimatedSprite.h"
#include <iostream>

MyMovement::MyMovement(Actor* owner) : MoveComponent(owner) {
    mPlayer = static_cast<Me*>(owner);
    mAnimatedSprite = mPlayer->GetAnimatedSprite();
}

void MyMovement::ProcessInput(const Uint8* keyState) {

    mDirection = South;
    xPos = 0.0f;
    yPos = 0.0f;
    mState = Moving;
    if (keyState[SDL_SCANCODE_S]){
        mDirection = South;
        xPos = 0.0f;
        yPos = SPEED;
    }
    else if (keyState[SDL_SCANCODE_W]){
        mDirection = North;
        xPos = 0.0f;
        yPos = -SPEED;
    }
    else if (keyState[SDL_SCANCODE_D]){
        mDirection = East;
        xPos = SPEED;
        yPos = 0.0f;
    }
    else if (keyState[SDL_SCANCODE_A]){
        mDirection = West;
        xPos = -SPEED;
        yPos = 0.0f;
    }
    else {
        mState = Idle;
    }
}
void MyMovement::Update(float deltaTime) {
    float mOwnerX = mOwner->GetPosition().GetX();
    float mOwnerY = mOwner->GetPosition().GetY();
    mOwner->SetPosition(mOwnerX + (xPos * deltaTime), mOwnerY + (yPos * deltaTime));
    
    UpdateAnimation();
}

void MyMovement::UpdateAnimation(){

    if (mState == Moving){
        std::string currAnim = mAnimatedSprite->GetAnimName();
        if (mDirection == South && currAnim != "walkdown"){
            mAnimatedSprite->SetAnimation("walkdown");
        }
        else if (mDirection == West && currAnim != "walkleft"){
            mAnimatedSprite->SetAnimation("walkleft");
        }
        else if (mDirection == East && currAnim != "walkright"){
            mAnimatedSprite->SetAnimation("walkright");
        }
        else if (mDirection == North && currAnim != "walkup"){
            mAnimatedSprite->SetAnimation("walkup");
        }

    }
    else if (mState == Idle){
        mAnimatedSprite->SetAnimation("idle");
    }
}