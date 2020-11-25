#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet)
	:sprite(sprite), textureSheet(texture_sheet)
{

}

AnimationComponent::~AnimationComponent()
{
	for (auto& i : this->animations)
	{
		delete i.second;
	}
}
//Funtions


void AnimationComponent::addAnimation(const std::string key, sf::Sprite& sprite, sf::Texture& texture_sheet,
	float animation_timer, int start_frames_x, int start_frames_y, int frames_x, int frames_y, int width, int height)
{
	this->animations[key] = new Animation(this->sprite, this->textureSheet,
		animation_timer,
		start_frames_x, start_frames_y, frames_x, frames_y, width, height);
}

void AnimationComponent::play(const std::string key, const float& dt)
{
	this->animations[key]->play(dt);
}
