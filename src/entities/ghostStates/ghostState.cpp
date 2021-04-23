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
