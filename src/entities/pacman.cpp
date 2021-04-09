//
// Created by Kacper on 19/03/2021.
//

#include <SFML/Window/Keyboard.hpp>
#include <systems/assetManager.hpp>
#include <cmath>
#include "pacman.hpp"
#include <iostream>

void Pacman::update(const sf::Time& time){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		dirKeyboard = Up;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		dirKeyboard = Down;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		dirKeyboard = Left;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		dirKeyboard = Right;
	
	if(dirKeyboard == Left && dir == Right){
		dir = Left;
		sprite.setAnimation(AssetManager::get().pacman.left);
	}
	else if(dirKeyboard == Right && dir == Left){
		dir = Right;
		sprite.setAnimation(AssetManager::get().pacman.right);
	}
	else if(dirKeyboard == Up && dir == Down){
		dir = Up;
		sprite.setAnimation(AssetManager::get().pacman.up);
	}
	else if(dirKeyboard == Down && dir == Up){
		dir = Down;
		sprite.setAnimation(AssetManager::get().pacman.down);
		
	}
	
	std::cout << pos.x << " " << pos.y << " " << dir << " " << dirKeyboard << "\n";
	
	sf::Vector2u pos2(pos.x + dx[dir], pos.y + dy[dir]);
	
	int dist = abs(sprite.getPosition().x - pos2.x * 12) + abs(sprite.getPosition().y - pos2.y * 12);
	int realDist = time.asMilliseconds() / 16;
	
	if(dist == 12){
		if(dir != dirKeyboard){
			dir = dirKeyboard;
			if(dir == Up)
				sprite.setAnimation(AssetManager::get().pacman.up);
			else if(dir == Down)
				sprite.setAnimation(AssetManager::get().pacman.down);
			else if(dir == Left)
				sprite.setAnimation(AssetManager::get().pacman.left);
			else if(dir == Right)
				sprite.setAnimation(AssetManager::get().pacman.right);
		}
	}
	
	std::cout << "\t" << dist << " " << sprite.getPosition().x << " " << sprite.getPosition().y << "\n";
	
	if(map.getField(pos2).isCanPass()){
		if(realDist >= dist){
			sprite.setPosition(pos2.x * 12, pos2.y * 12);
			
			pos = pos2;
			pos2 = sf::Vector2u(pos.x + dx[dir], pos.y + dy[dir]);
			
			realDist -= dist;
			if(dir != dirKeyboard){
				dir = dirKeyboard;
				if(dir == Up)
					sprite.setAnimation(AssetManager::get().pacman.up);
				else if(dir == Down)
					sprite.setAnimation(AssetManager::get().pacman.down);
				else if(dir == Left)
					sprite.setAnimation(AssetManager::get().pacman.left);
				else if(dir == Right)
					sprite.setAnimation(AssetManager::get().pacman.right);
			}
		}
		
		if(map.getField(pos2).isCanPass()){
			sprite.move(dx[dir] * realDist, dy[dir] * realDist);
			
			sprite.update(time);
		}
	}
}

void Pacman::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	target.draw(sprite, states);
}

Pacman::Pacman(Map& map) : map(map){
	pos.x = 13;
	pos.y = 23;
	sprite.setAnimation(AssetManager::get().pacman.left);
	sprite.setPosition(pos.x * 12, pos.y * 12);
	dirKeyboard = None;
	dir = Left;
}
