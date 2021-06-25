//
// Created by Kacper on 30/04/2021.
//

#include <systems/console.hpp>
#include <iostream>
#include "defaultGhostState.hpp"
#include "../ghost.hpp"
#include "fleeGhostState.hpp"

const std::vector<sf::Vector2u> DefaultGhostState::points[4] = {
		{sf::Vector2u(9, 17), sf::Vector2u(9, 3), sf::Vector2u(31, 3), sf::Vector2u(19, 12)},
        {sf::Vector2u(9, 59), sf::Vector2u(9, 41), sf::Vector2u(31, 41), sf::Vector2u(31, 53)},
        {sf::Vector2u(59, 17), sf::Vector2u(59, 3), sf::Vector2u(37, 3), sf::Vector2u(49, 12)},
		{sf::Vector2u(59, 58), sf::Vector2u(59, 41), sf::Vector2u(37, 41), sf::Vector2u(37, 53)}
}; // nie jestem pewny co do poprawności punktów, samo AI działa

DefaultGhostState::DefaultGhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack) : GhostState(fsm, ghost, assetPack){
	velocity = sf::milliseconds(110);
	ghost.setDestinationPoint(points[ghost.getCorner()][rand() % 4]);
}

void DefaultGhostState::calculateMove(){
	std::vector<sf::Vector2u> possible;
	
	if(ghost.getAiType() == Ghost::Follow || ghost.getSecondaryAiType() == Ghost::Follow){
		possible = ghost.getMap().findShortestPath(ghost.getPos(), ghost.getPacmanPos(), ghost.isPassDoor());
	}
	else if(ghost.getAiType() == Ghost::Ambush || ghost.getSecondaryAiType() == Ghost::Ambush) {
        sf::Vector2u target = ghost.getPacmanPos() + sf::Vector2u(dx[ghost.getPacmanDir()], dy[ghost.getPacmanDir()]);

        if (!ghost.getMap().getField(target).isCanPass())
            possible = ghost.getMap().findShortestPath(ghost.getPos(), ghost.getPacmanPos(), ghost.isPassDoor());
        else{
            possible = ghost.getMap().findShortestPath(ghost.getPos(),
                                                       target,
                                                       ghost.isPassDoor(),
                                                       ghost.getPacmanPos());
        }
	}
	else if(ghost.getAiType() == Ghost::Corner || ghost.getSecondaryAiType() == Ghost::Corner){
		std::vector<sf::Vector2u> path = ghost.getMap().findShortestPath(ghost.getPos(), ghost.getPacmanPos(), ghost.isPassDoor());
		unsigned distanceToPacman = path.size();
		if(distanceToPacman < 20){
			possible = path;
		}
		else{
		    if(ghost.getPos() == ghost.getDestinationPoint())
		        ghost.setDestinationPoint(points[ghost.getCorner()][rand() % points[ghost.getCorner()].size()]);
            possible = ghost.getMap().findShortestPath(ghost.getPos(), ghost.getDestinationPoint(), ghost.isPassDoor());
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
			gameEventSignal.notify(event1);
		}
	}
}

void DefaultGhostState::update(const sf::Time& time){
	GhostState::update(time);
	if(ghost.getPacmanPos() == ghost.getPos()){
		GameEvent event;
		event.type = GameEvent::PacmanEaten;
		gameEventSignal.notify(event);
	}
	if(ghost.getAiType() == Ghost::Mixed && ghost.getAiTime() >= sf::seconds(10)){
		ghost.setSecondaryAiType(static_cast<Ghost::AIType>(rand() % 3));
		ghost.setAiTime(sf::Time::Zero);
		ghost.setCorner(rand() % 4);
	}
	if(ghost.getAiType() == Ghost::Corner && ghost.getAiTime() >= sf::seconds(1)){
		ghost.setAiTime(sf::Time::Zero);
		ghost.setCorner(rand() % 4);
	}
}
