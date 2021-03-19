//
// Created by Kacper on 19/03/2021.
//

#include "animatedSprite.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	target.draw(sprite, states);
}

void AnimatedSprite::update(const sf::Time& time){
	deltaTime += time;
	while(deltaTime > frameTime){
		deltaTime -= frameTime;
		frame++;
		if(frame == animation->frameCount())
			frame = 0;
		sprite.setTexture(animation->getFrame(frame));
	}
}

void AnimatedSprite::setAnimation(Animation& animation){
	this->animation = &animation;
	deltaTime = sf::milliseconds(0);
}

void AnimatedSprite::setFrameTime(const sf::Time& time){
	frameTime = time;
}

AnimatedSprite::AnimatedSprite(){
	setFrameTime(sf::milliseconds(100));
}
