//
// Created by Kacper on 23/04/2021.
//

#ifndef PROGRAMOWANIEGIER_GHOSTSTATE_HPP
#define PROGRAMOWANIEGIER_GHOSTSTATE_HPP

#include <finiteStateMachine/finiteState.hpp>
#include <misc/animatedSprite.hpp>
#include <systems/assetManager.hpp>
#include <queue>
#include <gameEvent.hpp>

class Ghost;

class GhostState : public FiniteState, public Listener<GameEvent>{
	protected:
		AnimatedSprite sprite;
		Ghost& ghost;
		AssetManager::EntityAssetPack& assetPack;
		std::queue<sf::Vector2u> moves;
		
		sf::Vector2u pos2;
		sf::Vector2u nextMove();
	
		sf::Time velocity; // second required to get through one tile
		
		virtual void calculateMove() = 0;
	public:
		const AnimatedSprite& getSprite() const;
		
		virtual void update(const sf::Time& time);
		
		void forceRecalculate();
		
		GhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack);
		virtual ~GhostState();
};

#endif //PROGRAMOWANIEGIER_GHOSTSTATE_HPP
