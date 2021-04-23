//
// Created by Kacper on 26/03/2021.
//

#ifndef PROGRAMOWANIEGIER_FIELD_HPP
#define PROGRAMOWANIEGIER_FIELD_HPP

#include <SFML/Graphics/Sprite.hpp>
#include "../entities/entity.hpp"

class Field : public Entity{
	public:
		enum Type{
			Point,
			BigPoint,
			Cherry,
			Strawberry,
			Orange,
			Bell,
			Apple,
			Grapes,
			Empty,
			Wall,
			Door
		};
	private:
		Type type;
		bool canPass;
		sf::Sprite* sprite;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void update(const sf::Time& time) override;
		
		void setType(Type type, sf::Sprite& sprite);
		
		Type getType() const;
		
		bool isCanPass() const;
		
		Field(Type type, sf::Sprite& sprite);
};

#endif //PROGRAMOWANIEGIER_FIELD_HPP
