//
// Created by Kacper on 26/03/2021.
//

#ifndef PROGRAMOWANIEGIER_FIELD_HPP
#define PROGRAMOWANIEGIER_FIELD_HPP

#include <SFML/Graphics/Sprite.hpp>
#include "../entities/entity.hpp"

class Field{
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
	public:
		void setType(Type type);
		Type getType() const;
		
		bool isCanPass() const;
		
		Field(Type type);
		Field();
};

#endif //PROGRAMOWANIEGIER_FIELD_HPP
