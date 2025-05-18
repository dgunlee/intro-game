#pragma once
#include <SDL.h>
#include <vector>

class Actor {
public:
    Actor(class Game* game);
    virtual ~Actor();
    void Update(float deltaTime);
    void ProcessInput(const Uint8* keyState);

protected:
    virtual void OnUpdate(float deltaTime);
    virtual void OnProcessInput(const Uint8* keyState);

    std::vector<class Component*> mComponents;
    class Game* mGame;
private:
    friend class Component;
    void AddComponent(class Component* c);
};