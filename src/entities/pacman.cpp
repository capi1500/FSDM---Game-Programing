//
// Created by Kacper on 19/03/2021.
//

#include <SFML/Window/Keyboard.hpp>
#include <systems/assetManager.hpp>
#include <cmath>
#include "pacman.hpp"
#include <iostream>
#include <gameEvent.hpp>

void Pacman::update(const sf::Time& time){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		dirKeyboard = Up;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		dirKeyboard = Down;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		dirKeyboard = Left;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		dirKeyboard = Right;
	
	sf::Vector2u pos2(pos.x + dx[dir], pos.y + dy[dir]);
	
	int dist = abs(sprite.getPosition().x - pos2.x * 12) + abs(sprite.getPosition().y - pos2.y * 12);
	int realDist = time.asMilliseconds() / 16;
	
	if(dist == 12){
		if(dirKeyboard != None && dir != dirKeyboard){
			sf::Vector2u pos3 = sf::Vector2u(pos.x + dx[dirKeyboard], pos.y + dy[dirKeyboard]);
			if(map.getField(sf::Vector2u(pos3.y, pos3.x)).isCanPass()){
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
				dist = abs(sprite.getPosition().x - pos2.x * 12) + abs(sprite.getPosition().y - pos2.y * 12);
			}
		}
	}
	
	if(map.getField(sf::Vector2u(pos2.y, pos2.x)).isCanPass()){
		if(dirKeyboard == Left && dir == Right){
			std::swap(pos, pos2);
			dir = Left;
			dirKeyboard = None;
			sprite.setAnimation(AssetManager::get().pacman.left);
			sendSignal();
		}
		else if(dirKeyboard == Right && dir == Left){
			std::swap(pos, pos2);
			dir = Right;
			dirKeyboard = None;
			sprite.setAnimation(AssetManager::get().pacman.right);
			sendSignal();
		}
		else if(dirKeyboard == Up && dir == Down){
			std::swap(pos, pos2);
			dir = Up;
			dirKeyboard = None;
			sprite.setAnimation(AssetManager::get().pacman.up);
			sendSignal();
		}
		else if(dirKeyboard == Down && dir == Up){
			std::swap(pos, pos2);
			dir = Down;
			dirKeyboard = None;
			sprite.setAnimation(AssetManager::get().pacman.down);
			sendSignal();
		}
		dist = abs(sprite.getPosition().x - pos2.x * 12) + abs(sprite.getPosition().y - pos2.y * 12);
		
		while(realDist >= dist && map.getField(sf::Vector2u(pos2.y, pos2.x)).isCanPass()){
			sprite.setPosition(pos2.x * 12, pos2.y * 12);
			pos = pos2;
			pos2 = sf::Vector2u(pos.x + dx[dir], pos.y + dy[dir]);
			
			realDist -= dist;
			dist = abs(sprite.getPosition().x - pos2.x * 12) + abs(sprite.getPosition().y - pos2.y * 12);
			
			if(dirKeyboard != None && dir != dirKeyboard){
				sf::Vector2u pos3 = sf::Vector2u(pos.x + dx[dirKeyboard], pos.y + dy[dirKeyboard]);
				if(map.getField(sf::Vector2u(pos3.y, pos3.x)).isCanPass()){
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
			
			sendSignal();
		}
		
		if(map.getField(sf::Vector2u(pos2.y, pos2.x)).isCanPass()){
			sprite.move(dx[dir] * realDist, dy[dir] * realDist);
			sprite.update(time);
		}
	}

    if(pos.y == 14){
        if(pos2.x == 0){
            pos.x = 32;
            sprite.setPosition(pos.x * 12, pos.y * 12);
        }
        else if(pos2.x == 33){
            pos.x = 1;
            sprite.setPosition(pos.x * 12, pos.y * 12);
        }

        if (pos.x >= 32 && dir == Right) {
            dir = Left;
        } else if (pos.x <= 1 && dir == Left) {
            dir = Right;
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
}

void Pacman::sendSignal(){
	GameEvent event;
	event.type = GameEvent::PacmanMove;
	event.pacmanMove.direction = dir;
	event.pacmanMove.position = sf::Vector2u(pos.y, pos.x);
	gameEventSignal.notify(event);
}
