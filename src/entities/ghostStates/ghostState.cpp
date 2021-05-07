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
}

const AnimatedSprite& GhostState::getSprite() const{
	return sprite;
}

sf::Vector2u GhostState::nextMove(){
	if(moves.empty())
		calculateMove();
	sf::Vector2 out = moves.front();
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
	sf::Vector2 pos2 = nextMove();
	
	int dist = abs(sprite.getPosition().x - pos2.x * 12) + abs(sprite.getPosition().y - pos2.y * 12);
	int realDist = time.asMilliseconds() / 16;
	
	//std::clog << "update dist: " << dist << ", realDist: " << realDist << "\n";
	
	while(realDist >= dist){
		sprite.setPosition(pos2.x * 12, pos2.y * 12);
		ghost.setPos(pos2);
		moves.pop();
		pos2 = nextMove();
		if(pos2 == ghost.getPos())
			break;
		// TODO teleportowanie przez ściany
		
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
		
		// end TODO
		realDist -= dist;
		dist = abs(sprite.getPosition().x - pos2.x * 12) + abs(sprite.getPosition().y - pos2.y * 12);
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
