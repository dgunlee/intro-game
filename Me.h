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

    void SetJump(bool jump);
    bool GetJump() { return mIsJumping; }
    float GetJumpTimer() { return mJumpTimer; }

    void SetLastSpace(bool jump) { mLastSpace = jump; }
    bool GetLastSpace() { return mLastSpace; }

private:
    class MyMovement* mMyMovement;
    class AnimatedSprite* mAnimatedSprite;
    bool mIsJumping = false;
    float mJumpTimer = 0.0f;
    bool mLastSpace = false;
};