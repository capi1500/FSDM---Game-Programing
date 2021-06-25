//
// Created by Kacper on 12/03/2021.
//

#ifndef PROGRAMOWANIEGIER_GAMEEVENT_HPP
#define PROGRAMOWANIEGIER_GAMEEVENT_HPP

#include <signal/signal.hpp>
#include <entities/entity.hpp>
#include <SFML/System/Vector2.hpp>

class Fruit;

struct GameEvent{
	GameEvent();
	
	enum Type{
		Closed,
		PacmanMove,
		PacmanEaten,
		PacmanStarted,
		GhostEaten,
		GhostsRegenerated,
		BigPointEaten,
		SmallPointEaten,
		FruitEaten,
		NextLevel
	};
	
	struct PacmanMoveEvent{
		sf::Vector2u position;
		Entity::Direction direction;
	};
	
	struct FruitEatenEvent{
		Fruit* fruit;
	};
	
	Type type;
	
	union{
		PacmanMoveEvent pacmanMove;
		FruitEatenEvent fruitEaten;
	};
};

extern Signal<GameEvent> gameEventSignal;

#endif //PROGRAMOWANIEGIER_GAMEEVENT_HPP
