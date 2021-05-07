//
// Created by Kacper on 07/05/2021.
//

#ifndef PROGRAMOWANIEGIER_FLEEGHOSTSTATE_HPP
#define PROGRAMOWANIEGIER_FLEEGHOSTSTATE_HPP

#include "ghostState.hpp"

class FleeGhostState : public GhostState{
	private:
		bool atBase;
		sf::Time timeAtBase;
	protected:
		void calculateMove() override;
	public:
		void update(const sf::Time& time) override;
		
		void onNotify(const GameEvent& event) override;
		
		FleeGhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack);
};

#endif //PROGRAMOWANIEGIER_FLEEGHOSTSTATE_HPP
