//
// Created by Kacper on 19/03/2021.
//

#ifndef PROGRAMOWANIEGIER_PACMAN_HPP
#define PROGRAMOWANIEGIER_PACMAN_HPP

#include <misc/animatedSprite.hpp>
#include <map/map.hpp>
#include "entity.hpp"

class Pacman : public Entity, public Listener<GameEvent>{
	private:
		Direction dir;
		Direction dirKeyboard;
		
		Map& map;
		
		sf::Vector2u pos;
		AnimatedSprite sprite;
		
		sf::Time velocity; // second required to get through one tile
		sf::Time deltaTime; // time since last middle point
		
		void sendSignal();
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void update(const sf::Time& time) override;
		
		Pacman(Map& map);
		
		virtual ~Pacman();
		
		void onNotify(const GameEvent& event) override;
};

#endif //PROGRAMOWANIEGIER_PACMAN_HPP
