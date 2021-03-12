//
// Created by Kacper on 12/03/2021.
//

#ifndef PROGRAMOWANIEGIER_SMALLPOINT_HPP
#define PROGRAMOWANIEGIER_SMALLPOINT_HPP

#include "entity.hpp"
#include <SFML/Graphics/Sprite.hpp>

class SmallPoint : public Entity{
	private:
		sf::Sprite circle;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void update(const sf::Time& time) override;
		
		SmallPoint();
};

#endif //PROGRAMOWANIEGIER_SMALLPOINT_HPP
