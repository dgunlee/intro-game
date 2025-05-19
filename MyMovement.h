#pragma once
#include <SDL.h>
#include "MoveComponent.h"

enum Direction {
    North,
    South,
    East,
    West
};

enum State {
    Idle,
    Moving,
};

class MyMovement : public MoveComponent {
public:
    MyMovement(class Actor* owner);

    void ProcessInput(const Uint8* keyState) override;
    void Update(float deltaTime) override;
    void UpdateAnimation();

    const float SPEED = 20.0f;

private:
    class Me* mPlayer;
    Direction mDirection = South;
    State mState = Idle;        // Change with input
    class AnimatedSprite* mAnimatedSprite;

    float xPos = 0.0f;
    float yPos = 0.0f;

};