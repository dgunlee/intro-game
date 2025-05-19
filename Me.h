#pragma once
#include "Actor.h"

class Me : public Actor {
public:
    Me(class Game* game);
    ~Me();
    void OnUpdate(float deltaTime) override;

    class MyMovement* GetMyMovement() { return mMyMovement; }
    class AnimatedSprite* GetAnimatedSprite() { return mAnimatedSprite; }

    int DRAW_ORDER = 200;

private:
    class MyMovement* mMyMovement;
    class AnimatedSprite* mAnimatedSprite;
};