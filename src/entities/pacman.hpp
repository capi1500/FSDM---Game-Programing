//
// Created by Kacper on 19/03/2021.
//

#ifndef PROGRAMOWANIEGIER_PACMAN_HPP
#define PROGRAMOWANIEGIER_PACMAN_HPP

#include <misc/animatedSprite.hpp>
#include "entity.hpp"

class Pacman : public Entity{
	private:
		enum Direction{
			Up,
			Down,
			Left,
			Right
		};
		Direction dir;
		AnimatedSprite sprite;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void update(const sf::Time& time) override;
		
		Pacman();
};

#endif //PROGRAMOWANIEGIER_PACMAN_HPP
