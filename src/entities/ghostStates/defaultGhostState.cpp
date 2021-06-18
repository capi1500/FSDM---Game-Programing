//
// Created by Kacper on 30/04/2021.
//

#include <systems/console.hpp>
#include <iostream>
#include "defaultGhostState.hpp"
#include "../ghost.hpp"
#include "fleeGhostState.hpp"

const std::vector<sf::Vector2u>[4] DefaultGhostState::points = {
		{},
		{},
		{},
		{}
};

DefaultGhostState::DefaultGhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack) : GhostState(fsm, ghost, assetPack){
	velocity = sf::milliseconds(110);
}

void DefaultGhostState::calculateMove(){
	std::vector<sf::Vector2u> possible;
	
	if(ghost.getAiType() == Ghost::Follow || ghost.getSecondaryAiType() == Ghost::Follow){
		possible = ghost.getMap().findShortestPath(ghost.getPos(), ghost.getPacmanPos(), ghost.isPassDoor());
	}
	else if(ghost.getAiType() == Ghost::Ambush || ghost.getSecondaryAiType() == Ghost::Ambush){
		sf::Vector2u target = ghost.getPacmanPos() + sf::Vector2u(dx[ghost.getPacmanDir()], dy[ghost.getPacmanDir()]);
		
		if(!ghost.getMap().getField(target).isCanPass())
			possible = ghost.getMap().findShortestPath(ghost.getPos(), ghost.getPacmanPos(), ghost.isPassDoor());
		else
			possible = ghost.getMap().findShortestPath(ghost.getPos(),
			                                           target,
			                                           ghost.isPassDoor(),
			                                           ghost.getPacmanPos());
	}
	else if(ghost.getAiType() == Ghost::Corner || ghost.getSecondaryAiType() == Ghost::Corner){
		std::vector<sf::Vector2u> path = ghost.getMap().findShortestPath(ghost.getPos(), ghost.getPacmanPos(), ghost.isPassDoor());
		unsigned distanceToPacman = path.size();
		if(distanceToPacman < 20){
			possible = path;
		}
		else{
		
		}
	}
	
	if(possible.empty())
		moves.push(ghost.getPos());
	for(auto& v : possible)
		moves.push(v);
}

void DefaultGhostState::onNotify(const GameEvent& event){
	if(event.type == GameEvent::BigPointEaten){
		message.notify(Message("change ghost to flee", Message::Debug));
		fsm.replace(new FleeGhostState(fsm, ghost, defaultAssetPack));
	}
	else if(event.type == GameEvent::PacmanMove){
		if(event.pacmanMove.position == ghost.getPos()){
			GameEvent event1;
			event1.type = GameEvent::PacmanEaten;
			//gameEventSignal.notify(event1);
		}
	}
}

void DefaultGhostState::update(const sf::Time& time){
	GhostState::update(time);
	if(ghost.getPacmanPos() == ghost.getPos()){
		GameEvent event;
		event.type = GameEvent::PacmanEaten;
		//gameEventSignal.notify(event);
	}
	if(ghost.getAiType() == Ghost::Mixed && ghost.getAiTime() >= sf::seconds(10)){
		ghost.setSecondaryAiType(static_cast<Ghost::AIType>(rand() % 3));
		ghost.setAiTime(sf::Time::Zero);
		corner = rand() % 4;
	}
}
