//
// Created by Kacper on 12/03/2021.
//

#ifndef PROGRAMOWANIEGIER_GAME_HPP
#define PROGRAMOWANIEGIER_GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <finiteStateMachine/finiteStateMachine.hpp>
#include <systems/scene.hpp>
#include <map/map.hpp>
#include "gameEvent.hpp"

class Game : public Listener<GameEvent>{
	private:
		sf::RenderWindow window;
		FiniteStateMachine scenes;
		bool active;
		
		Scene* getScene();
		
		Map map;
	public:
		void run();
		
		void onNotify(const GameEvent& event) override;
		
		Game();
		~Game();
};

extern Signal<GameEvent> gameEventSignal;

#endif //PROGRAMOWANIEGIER_GAME_HPP
