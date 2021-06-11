//
// Created by Kacper on 28/05/2021.
//

#include <graphicSettings.hpp>
#include "fruit.hpp"
#include "ghost.hpp"

Fruit::Type Fruit::getType(){
	return type;
}

unsigned int Fruit::getPoints() const{
	return points;
}

Fruit::Fruit(Fruit::Type type, const sf::Vector2u& position){
	switch(type){
		case Cherry:
			sprite = &AssetManager::get().cherry;
			points = 100;
			break;
		case Strawberry:
			sprite = &AssetManager::get().strawberry;
			points = 300;
			break;
		case Orange:
			sprite = &AssetManager::get().orange;
			points = 500;
			break;
		case Apple:
			sprite = &AssetManager::get().apple;
			points = 700;
			break;
		case Melon:
			sprite = &AssetManager::get().melon;
			points = 1000;
			break;
		case Boss:
			sprite = &AssetManager::get().boss;
			points = 2000;
			break;
		case Bell:
			sprite = &AssetManager::get().bell;
			points = 3000;
			break;
		case Key:
			sprite = &AssetManager::get().key;
			points = 5000;
			break;
	}
	sprite->setPosition(position.x * GraphicSettings::fieldSize, position.y * GraphicSettings::fieldSize);
	this->position = position;
}

void Fruit::update(const sf::Time& time){

}

void Fruit::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	states.transform.translate(-GraphicSettings::fieldSize * 2, -GraphicSettings::fieldSize * 2);
	target.draw(*sprite, states);
}

void Fruit::onNotify(const GameEvent& event){
	if(event.type == GameEvent::PacmanMove){
		if(isExists() && event.pacmanMove.position == position){
			GameEvent event1;
			event1.type = GameEvent::FruitEaten;
			event1.fruitEaten.fruit = this;
			gameEventSignal.notify(event1);
			
			exists = false;
			gameEventSignal.removeListener(this);
		}
	}
}
