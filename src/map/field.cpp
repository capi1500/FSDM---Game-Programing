//
// Created by Kacper on 26/03/2021.
//

#include "field.hpp"

Field::Field(Field::Type type, sf::Sprite& sprite) : type(type), sprite(sprite){
}

void Field::update(const sf::Time& time){

}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	target.draw(sprite, states);
}
