//
// Created by Kacper on 19/03/2021.
//

#include <SFML/Window/Keyboard.hpp>
#include <systems/assetManager.hpp>
#include "pacman.hpp"

void Pacman::update(const sf::Time& time){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		sprite.move(0, -100 * time.asSeconds());
		if(dir != Up){
			dir = Up;
			sprite.setAnimation(AssetManager::get().pacman.up);
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		sprite.move(0, 100 * time.asSeconds());
		if(dir != Down){
			dir = Down;
			sprite.setAnimation(AssetManager::get().pacman.down);
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		sprite.move(-100 * time.asSeconds(), 0);
		if(dir != Left){
			dir = Left;
			sprite.setAnimation(AssetManager::get().pacman.left);
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		sprite.move(100 * time.asSeconds(), 0);
		if(dir != Right){
			dir = Right;
			sprite.setAnimation(AssetManager::get().pacman.right);
		}
	}
	sprite.update(time);
}

void Pacman::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	target.draw(sprite, states);
}

Pacman::Pacman(){
	sprite.setAnimation(AssetManager::get().pacman.right);
}
