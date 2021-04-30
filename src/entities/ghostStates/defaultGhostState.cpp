//
// Created by Kacper on 30/04/2021.
//

#include "defaultGhostState.hpp"
#include "../ghost.hpp"

DefaultGhostState::DefaultGhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack) : GhostState(fsm, ghost, assetPack){
}

void DefaultGhostState::calculateMove(){
	std::vector<sf::Vector2u> possible = ghost.getMap().findShortestPath(sf::Vector2u(ghost.getPos().y, ghost.getPos().x), sf::Vector2u(ghost.getPacmanPos().y, ghost.getPacmanPos().x));
	if(possible.empty())
		moves.push(ghost.getPos());
	for(auto& v : possible)
		moves.push(sf::Vector2u(v.y, v.x));
}
