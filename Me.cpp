#include "Me.h"
#include "Game.h"
#include "Actor.h"
#include "MyMovement.h"
#include "AnimatedSprite.h"
// #include "AnimatedSprite.h"

Me::Me(Game* game): Actor(game){
    
    mAnimatedSprite = new AnimatedSprite(this, DRAW_ORDER);
    mScale = 2.0f;

    // Add Animation
    std::vector<SDL_Texture*> idleAnim{GetGame()->GetTexture("assets/player/idle/idle.png")};
    std::vector<SDL_Texture*> walkDown{
        GetGame()->GetTexture("assets/player/walkDown/walkdown1.png"),
        GetGame()->GetTexture("assets/player/walkDown/walkdown2.png")};
    
    std::vector<SDL_Texture*> walkLeft{
        GetGame()->GetTexture("assets/player/walkleft/walkleft1.png"), 
        GetGame()->GetTexture("assets/player/walkleft/walkleft2.png")};
    
    std::vector<SDL_Texture*> walkRight{
        GetGame()->GetTexture("assets/player/walkright/walkright1.png"), 
        GetGame()->GetTexture("assets/player/walkright/walkright2.png")};

    std::vector<SDL_Texture*> walkUp{
        GetGame()->GetTexture("assets/player/walkup/walkup1.png"), 
        GetGame()->GetTexture("assets/player/walkup/walkup2.png")};
    // Give animation name
    mAnimatedSprite->AddAnimation("idle", idleAnim);
    mAnimatedSprite->AddAnimation("walkdown", walkDown);
    mAnimatedSprite->AddAnimation("walkleft", walkLeft);
    mAnimatedSprite->AddAnimation("walkright", walkRight);
    mAnimatedSprite->AddAnimation("walkup", walkUp);

    // Set initial animation
    mAnimatedSprite->SetAnimation("idle");

    mMyMovement = new MyMovement(this);
}

Me::~Me(){

}

void Me::OnUpdate(float deltaTime){

}