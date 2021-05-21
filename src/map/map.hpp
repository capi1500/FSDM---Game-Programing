//
// Created by Kacper on 26/03/2021.
//

#ifndef PROGRAMOWANIEGIER_MAP_HPP
#define PROGRAMOWANIEGIER_MAP_HPP

#include <gameEvent.hpp>
#include "field.hpp"

class Map : public sf::Drawable, public Listener<GameEvent>{
	private:
		std::vector<std::vector<Field>> fields;
		std::vector<std::vector<sf::Sprite*>> sprites;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		Field& getField(const sf::Vector2u& pos);
		Field& getField(const unsigned x, const unsigned y);
		const Field& getField(const sf::Vector2u& pos) const;
		const Field& getField(const unsigned x, const unsigned y) const;
		
		std::vector<sf::Vector2u> findShortestPath(const sf::Vector2u& v, const sf::Vector2u& u, bool canPassDoor) const;
		
		void onNotify(const GameEvent& event) override;
		
		Map();
};

#endif //PROGRAMOWANIEGIER_MAP_HPP
