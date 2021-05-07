//
// Created by Kacper on 23/04/2021.
//

#include "ghostState.hpp"
#include <entities/ghost.hpp>
#include <systems/console.hpp>
#include <iostream>

GhostState::GhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack)
		: FiniteState(fsm), ghost(ghost), assetPack(assetPack){
	sprite.setAnimation(assetPack.left);
	sprite.setPosition(ghost.getPos().x * 12, ghost.getPos().y * 12);
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
	//std::clog << "next move: (" << out.x << " " << out.y << ")\n";
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
	sf::Vector2u pos2 = nextMove();
	
	float dist = std::abs(sprite.getPosition().x - pos2.x * 12) + std::abs(sprite.getPosition().y - pos2.y * 12);
	float realDist = time.asSeconds() * 50 * speed;
	
	while(realDist >= dist){
		sprite.setPosition(pos2.x * 12, pos2.y * 12);
		ghost.setPos(pos2);
		moves.pop();
		pos2 = nextMove();
		realDist -= dist;
		
		if(pos2 == ghost.getPos())
			break;
		
		if(ghost.getPos().y == 14){
			if(pos2.x == 32){
				ghost.setPos(sf::Vector2u(31, 14));
				sprite.setPosition(31 * 12, 14 * 12);
			}
			else if(pos2.x == 0){
				ghost.setPos(sf::Vector2u(1, 14));
				sprite.setPosition(1 * 12, 14 * 12);
			}
			
			forceRecalculate();
			pos2 = nextMove();
			
			if(ghost.getPos().x == 31 && ghost.getDir() == Entity::Right){
				ghost.setDir(Entity::Left);
				sprite.setAnimation(assetPack.left);
			}
			else if(ghost.getPos().x == 1 && ghost.getDir() == Entity::Left){
				ghost.setDir(Entity::Right);
				sprite.setAnimation(assetPack.right);
			}
		}
		
		dist = std::abs(sprite.getPosition().x - pos2.x * 12) + std::abs(sprite.getPosition().y - pos2.y * 12);
	}
	
	if(pos2 != ghost.getPos()){
		sprite.move(dx[ghost.getDir()] * realDist, dy[ghost.getDir()] * realDist);
	}
	
	sprite.update(time);
}

void GhostState::forceRecalculate(){
	while(!moves.empty())
		moves.pop();
}
