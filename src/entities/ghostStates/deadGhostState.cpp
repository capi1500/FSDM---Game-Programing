//
// Created by Kacper on 07/05/2021.
//

#include <systems/console.hpp>
#include "deadGhostState.hpp"
#include "defaultGhostState.hpp"
#include "../ghost.hpp"

void DeadGhostState::calculateMove(){
	std::vector<sf::Vector2u> possible = ghost.getMap().findShortestPath(ghost.getPos(), sf::Vector2u(17, 14), ghost.isPassDoor());
	if(possible.empty())
		moves.push(ghost.getPos());
	for(auto& v : possible)
		moves.push(v);
}

DeadGhostState::DeadGhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack) : GhostState(fsm, ghost, assetPack){
	velocity = sf::milliseconds(150);
}

void DeadGhostState::onNotify(const GameEvent& event){

}

void DeadGhostState::update(const sf::Time& time){
	GhostState::update(time);
	if(ghost.getPos() == sf::Vector2u(17, 14)){
		if(!atBase){
			atBase = true;
			timeAtBase = sf::Time::Zero;
		}
		else{
			timeAtBase += time;
			if(timeAtBase >= sf::seconds(6)){
				atBase = false;
				message.notify(Message("change ghost to deafult", Message::Debug));
				fsm.replace(new DefaultGhostState(fsm, ghost, assetPack));
			}
		}
	}
}
