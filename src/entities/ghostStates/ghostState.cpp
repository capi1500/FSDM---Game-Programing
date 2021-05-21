//
// Created by Kacper on 23/04/2021.
//

#include "ghostState.hpp"
#include <entities/ghost.hpp>
#include <systems/console.hpp>
#include <iostream>
#include <graphicSettings.hpp>

GhostState::GhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack)
		: FiniteState(fsm), ghost(ghost), assetPack(assetPack){
	sprite.setAnimation(assetPack.left);
	sprite.setPosition(ghost.getPos().x * GraphicSettings::fieldSize, ghost.getPos().y * GraphicSettings::fieldSize);
	gameEventSignal.addListener(this);
}

GhostState::~GhostState(){
	gameEventSignal.removeListener(this);
}

const AnimatedSprite& GhostState::getSprite() const{
	return sprite;
}

sf::Vector2u GhostState::nextMove(){
	if(moves.empty())
		calculateMove();
	sf::Vector2u out = moves.front();
	if(out.y > ghost.getPos().y && ghost.getDir() != Entity::Down){
		ghost.setDir(Entity::Down);
		sprite.setAnimation(assetPack.down);
	}
	else if(out.y < ghost.getPos().y && ghost.getDir() != Entity::Up){
		ghost.setDir(Entity::Up);
		sprite.setAnimation(assetPack.up);
	}
	else if(out.x > ghost.getPos().x && ghost.getDir() != Entity::Right){
		ghost.setDir(Entity::Right);
		sprite.setAnimation(assetPack.right);
	}
	else if(out.x < ghost.getPos().x && ghost.getDir() != Entity::Left){
		ghost.setDir(Entity::Left);
		sprite.setAnimation(assetPack.left);
	}
	return out;
}

void GhostState::update(const sf::Time& time){
	ghost.setDeltaTime(ghost.getDeltaTime() + time);
	
	//Entity::Direction lastDir = ghost.getDir();
	//sf::Vector2u lastPos = ghost.getPos();
	//sf::Vector2u lastPos2(lastPos.x + dx[lastDir], lastPos.y + dy[lastDir]);
	
	pos2 = nextMove();
	
	// bug jest gdy np:
	//
	// duszek szedł w prawo, przed dotarciem zmienił się kierunek podróży na lewo
	
	/*if(ghost.getMap().getField(lastPos2).isCanPass() || (ghost.isPassDoor() && ghost.getMap().getField(lastPos2).getType() == Field::Door)){
		if(lastDir == Entity::Left && ghost.getDir() == Entity::Right){
			pos2 = ghost.getPos();
			moves.push(pos2);
			ghost.setPos(lastPos2);
			ghost.setDeltaTime(velocity - ghost.getDeltaTime());
		}
		else if(lastDir == Entity::Right && ghost.getDir() == Entity::Left){
			pos2 = ghost.getPos();
			moves.push(pos2);
			ghost.setPos(lastPos2);
			ghost.setDeltaTime(velocity - ghost.getDeltaTime());
		}
		else if(lastDir == Entity::Up && ghost.getDir() == Entity::Down){
			pos2 = ghost.getPos();
			moves.push(pos2);
			ghost.setPos(lastPos2);
			ghost.setDeltaTime(velocity - ghost.getDeltaTime());
		}
		else if(lastDir == Entity::Down && ghost.getDir() == Entity::Up){
			pos2 = ghost.getPos();
			moves.push(pos2);
			ghost.setPos(lastPos2);
			ghost.setDeltaTime(velocity - ghost.getDeltaTime());
		}
	}*/
	
	while(ghost.getDeltaTime() >= velocity){
		ghost.setPos(pos2);
		moves.pop();
		pos2 = nextMove();
		
		if(ghost.getPos().y == 28){
			if(pos2.x == 64){
				ghost.setPos(sf::Vector2u(62, 28));
			}
			else if(pos2.x == 0){
				ghost.setPos(sf::Vector2u(2, 28));
			}
			
			forceRecalculate();
			pos2 = nextMove();
			
			if(ghost.getPos().x == 62 && ghost.getDir() == Entity::Right){
				ghost.setDir(Entity::Left);
				sprite.setAnimation(assetPack.left);
			}
			else if(ghost.getPos().x == 2 && ghost.getDir() == Entity::Left){
				ghost.setDir(Entity::Right);
				sprite.setAnimation(assetPack.right);
			}
		}
		
		//if(pos2 != ghost.getPos())
		//	sprite.update(velocity);
			
		ghost.setDeltaTime(ghost.getDeltaTime() - velocity);
	}
	
	if(pos2 != ghost.getPos()){
		double change = GraphicSettings::fieldSize * ghost.getDeltaTime().asSeconds() / velocity.asSeconds();
		sprite.setPosition(
				ghost.getPos().x * GraphicSettings::fieldSize + dx[ghost.getDir()] * change,
				ghost.getPos().y * GraphicSettings::fieldSize + dy[ghost.getDir()] * change
		);
		sprite.update(time);
	}
	else{
		sprite.setPosition(
				ghost.getPos().x * GraphicSettings::fieldSize,
				ghost.getPos().y * GraphicSettings::fieldSize
		);
		ghost.setDeltaTime(sf::Time::Zero);
	}
}

void GhostState::forceRecalculate(){
	while(!moves.empty())
		moves.pop();
}
