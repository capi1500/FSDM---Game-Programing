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
	ghost.setDeltaTime(ghost.getDeltaTime() + time);
	
	sf::Vector2u pos2 = nextMove();
	
	while(ghost.getDeltaTime() >= velocity){
		ghost.setPos(pos2);
		moves.pop();
		pos2 = nextMove();
		
		if(ghost.getPos().y == 14){
			if(pos2.x == 32){
				ghost.setPos(sf::Vector2u(31, 14));
			}
			else if(pos2.x == 0){
				ghost.setPos(sf::Vector2u(1, 14));
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
		
		if(pos2 != ghost.getPos())
			sprite.update(velocity);
			
		ghost.setDeltaTime(ghost.getDeltaTime() - velocity);
	}
	
	if(pos2 != ghost.getPos()){
		double change = 12 * ghost.getDeltaTime().asSeconds() / velocity.asSeconds();
		sprite.setPosition(
				ghost.getPos().x * 12 + dx[ghost.getDir()] * change,
				ghost.getPos().y * 12 + dy[ghost.getDir()] * change
		);
		sprite.update(time);
	}
	else{
		ghost.setDeltaTime(sf::Time::Zero);
	}
}

void GhostState::forceRecalculate(){
	while(!moves.empty())
		moves.pop();
}
