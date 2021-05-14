//
// Created by Kacper on 19/03/2021.
//

#include <SFML/Window/Keyboard.hpp>
#include <systems/assetManager.hpp>
#include "pacman.hpp"
#include <gameEvent.hpp>

void Pacman::update(const sf::Time& time){
	deltaTime += time;
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		dirKeyboard = Up;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		dirKeyboard = Down;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		dirKeyboard = Left;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		dirKeyboard = Right;
	
	sf::Vector2u pos2(pos.x + dx[dir], pos.y + dy[dir]);
	
	if(map.getField(pos2).isCanPass()){
		if(dirKeyboard == Left && dir == Right){
			std::swap(pos, pos2);
			dir = Left;
			dirKeyboard = None;
			deltaTime = velocity - deltaTime;
			sprite.setAnimation(AssetManager::get().pacman.left);
			sendSignal();
		}
		else if(dirKeyboard == Right && dir == Left){
			std::swap(pos, pos2);
			dir = Right;
			dirKeyboard = None;
			deltaTime = velocity - deltaTime;
			sprite.setAnimation(AssetManager::get().pacman.right);
			sendSignal();
		}
		else if(dirKeyboard == Up && dir == Down){
			std::swap(pos, pos2);
			dir = Up;
			dirKeyboard = None;
			deltaTime = velocity - deltaTime;
			sprite.setAnimation(AssetManager::get().pacman.up);
			sendSignal();
		}
		else if(dirKeyboard == Down && dir == Up){
			std::swap(pos, pos2);
			dir = Down;
			dirKeyboard = None;
			deltaTime = velocity - deltaTime;
			sprite.setAnimation(AssetManager::get().pacman.down);
			sendSignal();
		}
	}
	
	while(deltaTime >= velocity){
		if(map.getField(pos2).isCanPass()){
			pos = pos2;
			pos2 = sf::Vector2u(pos.x + dx[dir], pos.y + dy[dir]);
			
			if(pos.y == 14){
				if(pos2.x == 0){
					pos.x = 32;
				}
				else if(pos2.x == 33){
					pos.x = 1;
				}
				
				if(pos.x >= 32 && dir == Right){
					dir = Left;
				}
				else if(pos.x <= 1 && dir == Left){
					dir = Right;
				}
				pos2 = sf::Vector2u(pos.x + dx[dir], pos.y + dy[dir]);
			}
			
			if(dirKeyboard != None && dir != dirKeyboard){
				sf::Vector2u pos3 = sf::Vector2u(pos.x + dx[dirKeyboard], pos.y + dy[dirKeyboard]);
				if(map.getField(pos3).isCanPass()){
					dir = dirKeyboard;
					dirKeyboard = None;
					if(dir == Up)
						sprite.setAnimation(AssetManager::get().pacman.up);
					else if(dir == Down)
						sprite.setAnimation(AssetManager::get().pacman.down);
					else if(dir == Left)
						sprite.setAnimation(AssetManager::get().pacman.left);
					else if(dir == Right)
						sprite.setAnimation(AssetManager::get().pacman.right);
					pos2 = pos3;
				}
			}
			sprite.update(velocity);
			
			sendSignal();
		}
		deltaTime -= velocity;
	}
	
	if(map.getField(pos2).isCanPass()){
		double change = 12 * deltaTime.asSeconds() / velocity.asSeconds();
		sprite.setPosition(pos.x * 12 + dx[dir] * change, pos.y * 12 + dy[dir] * change);
		sprite.update(time);
	}
	else{
		if(dirKeyboard != None && dir != dirKeyboard){
			sf::Vector2u pos3 = sf::Vector2u(pos.x + dx[dirKeyboard], pos.y + dy[dirKeyboard]);
			if(map.getField(pos3).isCanPass()){
				dir = dirKeyboard;
				dirKeyboard = None;
				if(dir == Up)
					sprite.setAnimation(AssetManager::get().pacman.up);
				else if(dir == Down)
					sprite.setAnimation(AssetManager::get().pacman.down);
				else if(dir == Left)
					sprite.setAnimation(AssetManager::get().pacman.left);
				else if(dir == Right)
					sprite.setAnimation(AssetManager::get().pacman.right);
				pos2 = pos3;
			}
		}
	}
}

void Pacman::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	states.transform.translate(-6, -6);
	target.draw(sprite, states);
}

Pacman::Pacman(Map& map) : map(map){
	pos.x = 16;
	pos.y = 23;
	sprite.setAnimation(AssetManager::get().pacman.left);
	sprite.setPosition(pos.x * 12, pos.y * 12);
	dirKeyboard = None;
	dir = Left;
	
	velocity = sf::milliseconds(200);
	deltaTime = sf::Time::Zero;
}

void Pacman::sendSignal(){
	GameEvent event;
	event.type = GameEvent::PacmanMove;
	event.pacmanMove.direction = dir;
	event.pacmanMove.position = pos;
	gameEventSignal.notify(event);
}
