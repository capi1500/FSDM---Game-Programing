//
// Created by Kacper on 12/03/2021.
//

#ifndef PROGRAMOWANIEGIER_GAMEEVENT_HPP
#define PROGRAMOWANIEGIER_GAMEEVENT_HPP

#include <signal/signal.hpp>
#include <entities/entity.hpp>
#include <SFML/System/Vector2.hpp>

struct GameEvent{
	GameEvent();
	
	enum Type{
		Closed,
		PacmanMove,
		BigPointEaten
	};
	
	struct PacmanMoveEvent{
		sf::Vector2u position;
		Entity::Direction direction;
	};
	
	Type type;
	
	union{
		PacmanMoveEvent pacmanMove;
	};
};

extern Signal<GameEvent> gameEventSignal;

#endif //PROGRAMOWANIEGIER_GAMEEVENT_HPP
