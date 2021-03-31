//
// Created by Kacper on 19/03/2021.
//

#include <systems/assetManager.hpp>
#include "fruit.hpp"

void Fruit::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	target.draw(*fruit, states);
}

void Fruit::update(const sf::Time& time){

}

Fruit::Fruit(Fruit::Type type){
	switch(type){
		case Cherry:
			fruit = &AssetManager::get().cherry;
			break;
		case Strawberry:
			fruit = &AssetManager::get().strawberry;
			break;
		case Orange:
			fruit = &AssetManager::get().orange;
			break;
		case Bell:
			fruit = &AssetManager::get().bell;
			break;
		case Apple:
			fruit = &AssetManager::get().apple;
			break;
		case Grapes:
			fruit = &AssetManager::get().grapes;
			break;
	}
}
