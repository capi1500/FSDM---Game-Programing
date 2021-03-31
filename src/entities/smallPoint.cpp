//
// Created by Kacper on 12/03/2021.
//

#include <systems/assetManager.hpp>
#include "smallPoint.hpp"

void SmallPoint::update(const sf::Time& time){

}

void SmallPoint::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	target.draw(*circle, states);
}

SmallPoint::SmallPoint(){
	circle = &AssetManager::get().smallCircle;
	setPosition(50, 50);
}
