//
// Created by Kacper on 23/04/2021.
//

#include "ghostState.hpp"
#include <entities/ghost.hpp>

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
	sf::Vector2 out = moves.top();
	moves.pop();
	if(out.y > ghost.getPos().y)
		ghost.setDir(Entity::Down);
	else if(out.y < ghost.getPos().y)
		ghost.setDir(Entity::Up);
	else if(out.x > ghost.getPos().x)
		ghost.setDir(Entity::Right);
	else if(out.x < ghost.getPos().x)
		ghost.setDir(Entity::Left);
	return out;
}

void GhostState::update(const sf::Time& time){
	while(!moves.empty())
		moves.pop();
	
	sf::Vector2 pos2 = nextMove();
	
	int dist = abs(sprite.getPosition().x - pos2.x * 12) + abs(sprite.getPosition().y - pos2.y * 12);
	int realDist = time.asMilliseconds() / 16;
	
	while(realDist >= dist){
		sprite.setPosition(pos2.x * 12, pos2.y * 12);
		ghost.setPos(pos2);
		pos2 = nextMove();
		if(pos2 == ghost.getPos())
			break;
		// TODO teleportowanie przez ściany
		realDist -= dist;
		dist = abs(sprite.getPosition().x - pos2.x * 12) + abs(sprite.getPosition().y - pos2.y * 12);
	}
	
	if(pos2 != ghost.getPos()){
		sprite.move(dx[ghost.getDir()] * realDist, dy[ghost.getDir()] * realDist);
		sprite.update(time);
	}
}
