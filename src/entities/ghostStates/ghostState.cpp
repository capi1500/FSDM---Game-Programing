//
// Created by Kacper on 23/04/2021.
//

#include "ghostState.hpp"
#include <entities/ghost.hpp>
#include <systems/console.hpp>
#include <iostream>
#include <graphicSettings.hpp>

GhostState::GhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack) : GhostState(fsm, ghost, assetPack, assetPack){
}

GhostState::GhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack, AssetManager::EntityAssetPack& defaultAssetPack)
		: FiniteState(fsm), ghost(ghost), assetPack(assetPack), defaultAssetPack(defaultAssetPack){
	if(ghost.getDir() == Entity::Left)
		sprite.setAnimation(assetPack.left);
	else if(ghost.getDir() == Entity::Right)
		sprite.setAnimation(assetPack.right);
	else if(ghost.getDir() == Entity::Up)
		sprite.setAnimation(assetPack.up);
	else
		sprite.setAnimation(assetPack.down);
	
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
	
	pos2 = nextMove();
	
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
		
		ghost.setDeltaTime(ghost.getDeltaTime() - velocity);
	}
	
	if(pos2 != ghost.getPos()){
		double change = GraphicSettings::fieldSize * ghost.getDeltaTime().asSeconds() / velocity.asSeconds();
		sprite.setPosition(
				ghost.getPos().x * GraphicSettings::fieldSize + dx[ghost.getDir()] * change,
				ghost.getPos().y * GraphicSettings::fieldSize + dy[ghost.getDir()] * change
		);
	}
	else{
		sprite.setPosition(
				ghost.getPos().x * GraphicSettings::fieldSize,
				ghost.getPos().y * GraphicSettings::fieldSize
		);
		ghost.setDeltaTime(sf::Time::Zero);
	}
	sprite.update(time);
}

void GhostState::forceRecalculate(){
	while(!moves.empty())
		moves.pop();
}
