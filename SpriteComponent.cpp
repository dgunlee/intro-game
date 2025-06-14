/*
    Taken from Professor Sanjay from USC ITP 380
*/
#include "SpriteComponent.h"
#include "Actor.h"
#include "Game.h"
#include <iostream>
SpriteComponent::SpriteComponent(Actor* owner, int drawOrder)
: Component(owner)
, mTexture(nullptr)
, mDrawOrder(drawOrder)
, mTexWidth(0)
, mTexHeight(0)
, mIsVisible(true)
{
	mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
	if (mTexture)
	{
		SDL_Rect r;
		r.w = static_cast<int>(mTexWidth * mOwner->GetScale());
		r.h = static_cast<int>(mTexHeight * mOwner->GetScale());

		// Center the rectangle around the position of the owner
		r.x = static_cast<int>(mOwner->GetPosition().GetX() - r.w / 2);
		r.y = static_cast<int>(mOwner->GetPosition().GetY() - r.h / 2);

        SDL_RenderCopyEx(
            renderer, 
            mTexture, 
            nullptr, 
            &r, 
            0.0,
            nullptr, 
            SDL_FLIP_NONE);
	}
}

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
	mTexture = texture;
	// Set width/height
	SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
}
