#pragma once
#include <SDL.h>
#include <vector>

class Component {
public:
    Component(class Actor* actor);
    virtual ~Component();
    virtual void Update(float deltaTime);
    virtual void ProcessInput(const Uint8* keyState);
    class Actor* GetActor() const;

protected:
    class Actor* mActor;
};