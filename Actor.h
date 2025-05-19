#pragma once
#include <SDL.h>
#include <vector>
#include "Position.h"

class Actor {
public:
    Actor(class Game* game);
    virtual ~Actor();
    void Update(float deltaTime);
    void ProcessInput(const Uint8* keyState);
    void SetPosition(float x, float y);
    void SetPosition(int x, int y);
    class Game* GetGame();
    Position GetPosition(); 
    float GetScale() const { return mScale; }
    void SetScale(float scale) { mScale = scale; }

protected:
    virtual void OnUpdate(float deltaTime);
    virtual void OnProcessInput(const Uint8* keyState);

    std::vector<class Component*> mComponents;
    class Game* mGame;
    Position pos;
    float mScale;

private:
    friend class Component;
    void AddComponent(class Component* c);
};