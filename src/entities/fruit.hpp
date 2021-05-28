//
// Created by Kacper on 28/05/2021.
//

#ifndef PROGRAMOWANIEGIER_FRUIT_HPP
#define PROGRAMOWANIEGIER_FRUIT_HPP

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
		
};

#endif //PROGRAMOWANIEGIER_FRUIT_HPP
