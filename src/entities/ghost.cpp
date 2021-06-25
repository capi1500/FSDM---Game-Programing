//
// Created by Kacper on 23/04/2021.
//

#include <systems/console.hpp>
#include <graphicSettings.hpp>
#include "ghost.hpp"
#include "ghostStates/defaultGhostState.hpp"

Entity::Direction Ghost::getDir() const{
	return dir;
}

void Ghost::setDir(Entity::Direction dir){
	this->dir = dir;
}

const sf::Vector2u& Ghost::getPos() const{
	return pos;
}

void Ghost::setPos(const sf::Vector2u& pos){
	message.notify(Message("ghost moved (" + std::to_string(pos.x) + ", " + std::to_string(pos.y) + ") " + std::to_string(deltaTime.asMilliseconds()), Message::Debug));
	this->pos = pos;
}

GhostState* Ghost::getState(){
	return static_cast<GhostState*>(fsm.get());
}

void Ghost::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	if(isVisible()){
		states.transform.combine(getTransform());
		states.transform.translate(-GraphicSettings::fieldSize * 2, -GraphicSettings::fieldSize * 2);
		target.draw(state->getSprite(), states);
	}
}

void Ghost::update(const sf::Time& time){
	if(active){
		state = getState();
		state->update(time);
		aiTime += time;
	}
}

void Ghost::onNotify(const GameEvent& event){
	if(event.type == GameEvent::PacmanMove){
		pacmanPos = event.pacmanMove.position;
		pacmanDir = event.pacmanMove.direction;
		getState()->forceRecalculate();
	}
	else if(event.type == GameEvent::PacmanEaten){
		pos = startingPos;
		getState()->forceRecalculate();
		visible = false;
		active = false;
	}
	else if(event.type == GameEvent::PacmanStarted){
		visible = true;
		active = true;
	}
}

Map& Ghost::getMap() const{
	return map;
}

const sf::Vector2u& Ghost::getPacmanPos() const{
	return pacmanPos;
}

Ghost::Ghost(Map& map, sf::Vector2u position, AIType type) : map(map), aiType(type), secondaryAIType(None){
	dir = Up;
	startingPos = position;
	passDoor = true;
	pos = position;
	pacmanDir = Left;
	pacmanPos.x = 33;
	pacmanPos.y = 47;
	deltaTime = sf::Time::Zero;
	corner = 0;
	gameEventSignal.addListener(this);
	if(aiType == Follow)
		fsm.add(new DefaultGhostState(fsm, *this, AssetManager::get().redGhost));
	else if(aiType == Ambush)
		fsm.add(new DefaultGhostState(fsm, *this, AssetManager::get().cyanGhost));
	else if(aiType == Corner){
		corner = rand() % 4;
		fsm.add(new DefaultGhostState(fsm, *this, AssetManager::get().pinkGhost));
	}
	else if(aiType == Mixed){
		fsm.add(new DefaultGhostState(fsm, *this, AssetManager::get().orangeGhost));
		secondaryAIType = static_cast<AIType>(rand() % 3);
		corner = rand() % 4;
	}
}

Ghost::~Ghost(){
	fsm.clear();
	gameEventSignal.removeListener(this);
}

bool Ghost::isPassDoor() const{
	return passDoor;
}

void Ghost::setPassDoor(bool passDoor){
	Ghost::passDoor = passDoor;
}

const sf::Time& Ghost::getDeltaTime() const{
	return deltaTime;
}

void Ghost::setDeltaTime(const sf::Time& deltaTime){
	Ghost::deltaTime = deltaTime;
}

Ghost::AIType Ghost::getAiType() const{
	return aiType;
}

const sf::Time& Ghost::getAiTime() const{
	return aiTime;
}

void Ghost::setAiTime(const sf::Time& aiTime){
	this->aiTime = aiTime;
}

Ghost::AIType Ghost::getSecondaryAiType() const{
	return secondaryAIType;
}

void Ghost::setSecondaryAiType(Ghost::AIType secondaryAiType){
	secondaryAIType = secondaryAiType;
}

Entity::Direction Ghost::getPacmanDir() const{
	return pacmanDir;
}

unsigned int Ghost::getCorner() const{
	return corner;
}

void Ghost::setCorner(unsigned int corner){
	Ghost::corner = corner;
}

const sf::Vector2u &Ghost::getDestinationPoint() const {
    return destinationPoint;
}

void Ghost::setDestinationPoint(const sf::Vector2u &destinationPoint) {
    Ghost::destinationPoint = destinationPoint;
}
