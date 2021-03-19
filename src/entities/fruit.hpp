//
// Created by Kacper on 19/03/2021.
//

#ifndef PROGRAMOWANIEGIER_FRUIT_HPP
#define PROGRAMOWANIEGIER_FRUIT_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "entity.hpp"

class Fruit : public Entity{
	public:
		enum Type{
			Cherry,
			Strawberry,
			Orange,
			Bell,
			Apple,
			Grapes
		};
	private:
		sf::Sprite fruit;
		Type type;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void update(const sf::Time& time) override;
		
		Fruit(Type type);
};

#endif //PROGRAMOWANIEGIER_FRUIT_HPP
