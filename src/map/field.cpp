//
// Created by Kacper on 26/03/2021.
//

#include "field.hpp"

Field::Field(Field::Type type, sf::Sprite& sprite) : sprite(&sprite){
	setType(type, sprite);
}


Field::Field(){
	type = Type::Empty;
	sprite = nullptr;
}

void Field::update(const sf::Time& time){

}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	target.draw(*sprite, states);
}

Field::Type Field::getType() const{
	return type;
}

bool Field::isCanPass() const{
	return canPass;
}

void Field::setType(Field::Type type, sf::Sprite& sprite){
	Field::type = type;
	this->sprite = &sprite;
	canPass = (type != Door && type != Wall);
}
