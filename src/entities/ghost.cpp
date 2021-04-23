//
// Created by Kacper on 23/04/2021.
//

#include "ghost.hpp"

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
	fsm.add(new GhostState(fsm, *this, AssetManager::get().redGhost));
}

void Ghost::onNotify(const GameEvent& event){

}
