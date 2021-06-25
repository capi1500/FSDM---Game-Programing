//
// Created by Kacper on 07/05/2021.
//

#include <systems/console.hpp>
#include "fleeGhostState.hpp"
#include "../ghost.hpp"
#include "defaultGhostState.hpp"
#include "deadGhostState.hpp"

void FleeGhostState::calculateMove(){
	std::vector<sf::Vector2u> possible = ghost.getMap().findShortestPath(ghost.getPos(), sf::Vector2u(34, 28), ghost.isPassDoor());
	if(possible.empty()){
		moves.push(ghost.getPos());
	}
	for(auto& v : possible)
		moves.push(v);
}

FleeGhostState::FleeGhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack) : GhostState(fsm, ghost, AssetManager::get().fleeGhost, assetPack){
	 velocity = sf::milliseconds(200);
}

void FleeGhostState::update(const sf::Time& time){
	GhostState::update(time);
	if(ghost.getPos() == sf::Vector2u(34, 28)){
		if(!atBase){
			atBase = true;
			timeAtBase = sf::Time::Zero;
		}
		else{
			timeAtBase += time;
			if(timeAtBase >= sf::seconds(3)){
				atBase = false;
				
				GameEvent event;
				event.type = GameEvent::GhostsRegenerated;
				
				gameEventSignal.notify(event);
				ghost.setCorner(rand() % 4);
				message.notify(Message("change ghost to deafult", Message::Debug));
				fsm.replace(new DefaultGhostState(fsm, ghost, defaultAssetPack));
			}
		}
	}
}

void FleeGhostState::onNotify(const GameEvent& event){
	if(event.type == GameEvent::PacmanMove){
		if(event.pacmanMove.position == ghost.getPos()){
			GameEvent event;
			event.type = GameEvent::GhostEaten;
			
			gameEventSignal.notify(event);
			message.notify(Message("change ghost to dead", Message::Debug));
			fsm.replace(new DeadGhostState(fsm, ghost, defaultAssetPack));
		}
	}
}
