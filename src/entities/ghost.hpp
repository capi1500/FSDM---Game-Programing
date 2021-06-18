//
// Created by Kacper on 23/04/2021.
//

#ifndef PROGRAMOWANIEGIER_GHOST_HPP
#define PROGRAMOWANIEGIER_GHOST_HPP

#include <gameEvent.hpp>
#include <map/map.hpp>
#include <game.hpp>
#include <entities/ghostStates/ghostState.hpp>

class Ghost : public Entity, public Listener<GameEvent>{
	public:
		enum AIType{
			Follow,
			Ambush,
			Corner,
			Mixed,
			None
		};
	private:
		Map& map;
		
		sf::Vector2u startingPos;
		Direction dir;
		sf::Vector2u pos;
		sf::Vector2u pacmanPos = sf::Vector2u(1000, 1000);
		Direction pacmanDir;
		bool passDoor;
		
		sf::Time deltaTime; // time since last middle point
		
		AIType aiType;
		unsigned corner;
		sf::Time aiTime;
		AIType secondaryAIType;
		
		FiniteStateMachine fsm;
		GhostState* state;
		
		GhostState* getState();
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		const sf::Time& getAiTime() const;
		void setAiTime(const sf::Time& aiTime);
		AIType getSecondaryAiType() const;
		void setSecondaryAiType(AIType secondaryAiType);
		unsigned int getCorner() const;
		void setCorner(unsigned int corner);
		AIType getAiType() const;
		Direction getDir() const;
		void setDir(Direction dir);
		const sf::Vector2u& getPos() const;
		void setPos(const sf::Vector2u& pos);
		const sf::Vector2u& getPacmanPos() const;
		bool isPassDoor() const;
		void setPassDoor(bool passDoor);
		Direction getPacmanDir() const;
		const sf::Time& getDeltaTime() const;
		
		void setDeltaTime(const sf::Time& deltaTime);
		
		Map& getMap() const;
		
		void onNotify(const GameEvent& event) override;
		
		void update(const sf::Time& time) override;
		
		Ghost(Map& map, sf::Vector2u position, AIType type);
		
		virtual ~Ghost();
};

#endif //PROGRAMOWANIEGIER_GHOST_HPP
