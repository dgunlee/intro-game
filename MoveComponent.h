#pragma once
#include "Component.h"

class MoveComponent : public Component {
public:
    MoveComponent(class Actor* owner);

    void Update(float deltaTime) override;
    

    float GetForwardSpeed() const {return mForwardSpeed; }
    void SetForwardSpeed(float speed) { mForwardSpeed = speed; }

protected:
    float mForwardSpeed;
};