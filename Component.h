#pragma once
#include <SDL.h>
#include <vector>

class Component {
public:
    Component(class Actor* actor, int UpdateOrder = 100);
    virtual ~Component();
    virtual void Update(float deltaTime);
    virtual void ProcessInput(const Uint8* keyState);
    class Actor* GetActor() const;
    class Game* GetGame() const;
    int GetUpdateOrder() const { return mUpdateOrder; }

protected:
    class Actor* mOwner;
    int mUpdateOrder;
};