//
// Created by Kacper on 19/03/2021.
//

#ifndef PROGRAMOWANIEGIER_PACMAN_HPP
#define PROGRAMOWANIEGIER_PACMAN_HPP

#include <misc/animatedSprite.hpp>
#include <map/map.hpp>
#include "entity.hpp"

class Pacman : public Entity{
	private:
		Direction dir;
		Direction dirKeyboard;
		
		Map& map;
		
		sf::Vector2u pos;
		AnimatedSprite sprite;
		
		void sendSignal();
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void update(const sf::Time& time) override;
		
		Pacman(Map& map);
};

#endif //PROGRAMOWANIEGIER_PACMAN_HPP
