//
// Created by Kacper on 28/05/2021.
//

#ifndef PROGRAMOWANIEGIER_FRUIT_HPP
#define PROGRAMOWANIEGIER_FRUIT_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <signal/listener.hpp>
#include <gameEvent.hpp>
#include "entity.hpp"

class Fruit : public Entity, public Listener<GameEvent>{
	public:
		enum Type{
			Cherry,
			Strawberry,
			Orange,
			Apple,
			Melon,
			Boss,
			Bell,
			Key,
			Count
		};
	private:
		sf::Vector2u position;
		Type type;
		unsigned points;
		sf::Sprite* sprite;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		Type getType();
		unsigned int getPoints() const;
		void onNotify(const GameEvent& event) override;
		void update(const sf::Time& time) override;
		
		Fruit(Type type, const sf::Vector2u& position);
};

#endif //PROGRAMOWANIEGIER_FRUIT_HPP
