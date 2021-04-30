//
// Created by Kacper on 23/04/2021.
//

#ifndef PROGRAMOWANIEGIER_GHOSTSTATE_HPP
#define PROGRAMOWANIEGIER_GHOSTSTATE_HPP

#include <finiteStateMachine/finiteState.hpp>
#include <misc/animatedSprite.hpp>
#include <systems/assetManager.hpp>
#include <stack>

class Ghost;

class GhostState : public FiniteState{
	protected:
		AnimatedSprite sprite;
		Ghost& ghost;
		AssetManager::EntityAssetPack& assetPack;
		std::stack<sf::Vector2u> moves;
		sf::Vector2u nextMove();
		
		virtual void calculateMove() = 0;
	public:
		const AnimatedSprite& getSprite() const;
		
		void update(const sf::Time& time);
		
		GhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack);
};

#endif //PROGRAMOWANIEGIER_GHOSTSTATE_HPP
