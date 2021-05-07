//
// Created by Kacper on 07/05/2021.
//

#ifndef PROGRAMOWANIEGIER_DEADGHOSTSTATE_HPP
#define PROGRAMOWANIEGIER_DEADGHOSTSTATE_HPP

#include "ghostState.hpp"

class DeadGhostState : public GhostState{
	private:
		bool atBase;
		sf::Time timeAtBase;
	protected:
		void calculateMove() override;
	public:
		void onNotify(const GameEvent& event) override;
		
		void update(const sf::Time& time) override;
		
		DeadGhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack);
};

#endif //PROGRAMOWANIEGIER_DEADGHOSTSTATE_HPP
