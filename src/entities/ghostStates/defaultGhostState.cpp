//
// Created by Kacper on 30/04/2021.
//

#include <iostream>
#include "defaultGhostState.hpp"
#include "../ghost.hpp"

DefaultGhostState::DefaultGhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack) : GhostState(fsm, ghost, assetPack){
}

void DefaultGhostState::calculateMove(){
	std::vector<sf::Vector2u> possible = ghost.getMap().findShortestPath(ghost.getPos(), ghost.getPacmanPos());
	if(possible.empty())
		moves.push(ghost.getPos());
	for(auto& v : possible)
		moves.push(v);
}
