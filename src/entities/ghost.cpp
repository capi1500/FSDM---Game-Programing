//
// Created by Kacper on 23/04/2021.
//

#include "ghost.hpp"
#include "ghostStates/defaultGhostState.hpp"

Entity::Direction Ghost::getDir() const{
	return dir;
}

void Ghost::setDir(Entity::Direction dir){
	Ghost::dir = dir;
}

const sf::Vector2u& Ghost::getPos() const{
	return pos;
}

void Ghost::setPos(const sf::Vector2u& pos){
	Ghost::pos = pos;
}

GhostState* Ghost::getState(){
	return static_cast<GhostState*>(fsm.get());
}

void Ghost::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	states.transform.translate(-6, -6);
	target.draw(state->getSprite(), states);
}

void Ghost::update(const sf::Time& time){
	state = getState();
	state->update(time);
}

Ghost::Ghost(Map& map, sf::Vector2u position) : map(map){
	pos = position;
	gameEventSignal.addListener(this);
	fsm.add(new DefaultGhostState(fsm, *this, AssetManager::get().redGhost));
}

void Ghost::onNotify(const GameEvent& event){
	if(event.type == GameEvent::PacmanMove)
		pacmanPos = event.pacmanMove.position;
}

Map& Ghost::getMap() const{
	return map;
}

const sf::Vector2u& Ghost::getPacmanPos() const{
	return pacmanPos;
}
