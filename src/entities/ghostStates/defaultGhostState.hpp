//
// Created by Kacper on 30/04/2021.
//

#ifndef PROGRAMOWANIEGIER_DEFAULTGHOSTSTATE_HPP
#define PROGRAMOWANIEGIER_DEFAULTGHOSTSTATE_HPP

#include "ghostState.hpp"

class DefaultGhostState : public GhostState{
	protected:
		void calculateMove() override;
	public:
		DefaultGhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack);
};

#endif //PROGRAMOWANIEGIER_DEFAULTGHOSTSTATE_HPP
