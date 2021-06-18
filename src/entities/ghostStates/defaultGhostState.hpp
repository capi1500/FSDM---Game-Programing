//
// Created by Kacper on 30/04/2021.
//

#ifndef PROGRAMOWANIEGIER_DEFAULTGHOSTSTATE_HPP
#define PROGRAMOWANIEGIER_DEFAULTGHOSTSTATE_HPP

#include "ghostState.hpp"

class DefaultGhostState : public GhostState{
	protected:
		void calculateMove() override;
		static const std::vector<sf::Vector2u>[4] points;
	public:
		void onNotify(const GameEvent& event) override;
		
		void update(const sf::Time& time) override;
		
		DefaultGhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack);
};

#endif //PROGRAMOWANIEGIER_DEFAULTGHOSTSTATE_HPP
