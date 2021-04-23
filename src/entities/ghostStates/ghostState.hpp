//
// Created by Kacper on 23/04/2021.
//

#ifndef PROGRAMOWANIEGIER_GHOSTSTATE_HPP
#define PROGRAMOWANIEGIER_GHOSTSTATE_HPP

#include <finiteStateMachine/finiteState.hpp>
#include <misc/animatedSprite.hpp>
#include <systems/assetManager.hpp>

class Ghost;

class GhostState : public FiniteState{
	private:
		AnimatedSprite sprite;
		Ghost& ghost;
		AssetManager::EntityAssetPack& assetPack;
	public:
		const AnimatedSprite& getSprite() const;
		
		virtual void update(const sf::Time& time){
			sprite.update(time);
		};
		
		GhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack);
};

#endif //PROGRAMOWANIEGIER_GHOSTSTATE_HPP
