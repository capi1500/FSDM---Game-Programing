//
// Created by Kacper on 19/03/2021.
//

#include <systems/assetManager.hpp>
#include "fruit.hpp"

void Fruit::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	target.draw(fruit, states);
}

void Fruit::update(const sf::Time& time){

}

Fruit::Fruit(Fruit::Type type) : type(type){
	switch(type){
		case Cherry:
			fruit.setTexture(AssetManager::get().cherry);
			break;
		case Strawberry:
			fruit.setTexture(AssetManager::get().strawberry);
			break;
		case Orange:
			fruit.setTexture(AssetManager::get().orange);
			break;
		case Bell:
			fruit.setTexture(AssetManager::get().bell);
			break;
		case Apple:
			fruit.setTexture(AssetManager::get().apple);
			break;
		case Grapes:
			fruit.setTexture(AssetManager::get().grapes);
			break;
	}
}
