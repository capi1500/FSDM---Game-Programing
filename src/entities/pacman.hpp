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
		enum Direction{
			Up,
			Down,
			Left,
			Right,
			None
		};
		Direction dir;
		Direction dirKeyboard;
		
		int dx[4] = {0, 0, -1, 1};
		int dy[4] = {-1, 1, 0, 0};
		
		Map& map;
		
		sf::Vector2u pos;
		AnimatedSprite sprite;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void update(const sf::Time& time) override;
		
		Pacman(Map& map);
};

#endif //PROGRAMOWANIEGIER_PACMAN_HPP
