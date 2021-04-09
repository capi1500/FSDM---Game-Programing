//
// Created by Kacper on 19/03/2021.
//

#ifndef PROGRAMOWANIEGIER_ANIMATEDSPRITE_HPP
#define PROGRAMOWANIEGIER_ANIMATEDSPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include "animation.hpp"

class AnimatedSprite : public sf::Drawable, public sf::Transformable{
	private:
		Animation* animation;
		sf::Sprite sprite;
		sf::Time frameTime;
		sf::Time deltaTime;
		
		size_t frame;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void setFrameTime(const sf::Time& time);
		void update(const sf::Time& time);
		void setAnimation(Animation& animation);
		
		AnimatedSprite();
};

#endif //PROGRAMOWANIEGIER_ANIMATEDSPRITE_HPP
