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
	private:
		Map& map;
		
		sf::Vector2u startingPos;
		Direction dir;
		sf::Vector2u pos;
		sf::Vector2u pacmanPos = sf::Vector2u(1000, 1000);
		bool passDoor;
		
		sf::Time deltaTime; // time since last middle point
		
		FiniteStateMachine fsm;
		GhostState* state;
		
		GhostState* getState();
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		Direction getDir() const;
		void setDir(Direction dir);
		const sf::Vector2u& getPos() const;
		void setPos(const sf::Vector2u& pos);
		const sf::Vector2u& getPacmanPos() const;
		bool isPassDoor() const;
		void setPassDoor(bool passDoor);
		
		const sf::Time& getDeltaTime() const;
		
		void setDeltaTime(const sf::Time& deltaTime);
		
		Map& getMap() const;
		
		void onNotify(const GameEvent& event) override;
		
		void update(const sf::Time& time) override;
		
		Ghost(Map& map, sf::Vector2u position);
		
		virtual ~Ghost();
};

#endif //PROGRAMOWANIEGIER_GHOST_HPP
