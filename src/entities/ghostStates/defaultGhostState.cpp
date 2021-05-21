//
// Created by Kacper on 30/04/2021.
//

#include <systems/console.hpp>
#include "defaultGhostState.hpp"
#include "../ghost.hpp"
#include "fleeGhostState.hpp"

DefaultGhostState::DefaultGhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack) : GhostState(fsm, ghost, assetPack){
	velocity = sf::milliseconds(110);
}

void DefaultGhostState::calculateMove(){
	std::vector<sf::Vector2u> possible = ghost.getMap().findShortestPath(ghost.getPos(), ghost.getPacmanPos(), ghost.isPassDoor());
	if(possible.empty())
		moves.push(ghost.getPos());
	for(auto& v : possible)
		moves.push(v);
}

void DefaultGhostState::onNotify(const GameEvent& event){
	if(event.type == GameEvent::BigPointEaten){
		message.notify(Message("change ghost to flee", Message::Debug));
		fsm.replace(new FleeGhostState(fsm, ghost, assetPack));
	}
}
