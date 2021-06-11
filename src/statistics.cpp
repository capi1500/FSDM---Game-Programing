//
// Created by Kacper on 28/05/2021.
//

#include <systems/assetManager.hpp>
#include "statistics.hpp"
#include <entities/fruit.hpp>

void Statistics::onNotify(const GameEvent& event){
	if(event.type == GameEvent::PacmanEaten){
		lives--;
		if(lives == 0){
			GameEvent gameEvent;
			gameEvent.type = GameEvent::Closed;
			gameEventSignal.notify(gameEvent);
		}
	}
	else if(event.type == GameEvent::BigPointEaten){
		setPoints(getPoints() + 50);
	}
	else if(event.type == GameEvent::SmallPointEaten){
		setPoints(getPoints() + 10);
		pointsEaten++;
	}
	else if(event.type == GameEvent::FruitEaten){
		setPoints(getPoints() + event.fruitEaten.fruit->getPoints());
	}
	else if(event.type == GameEvent::NextLevel){
		pointsEaten = 0;
	}
	else if(event.type == GameEvent::GhostEaten){
		setPoints(getPoints() + (1 << (ghostsEatenStreak + 1)) * 100);
	}
	else if(event.type == GameEvent::GhostsRegenerated){
		ghostsEatenStreak = 0;
	}
}

void Statistics::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(highScoreText, states);
	target.draw(levelText, states);
	target.draw(pointsText, states);
	for(unsigned i = 0; i < lives; i++){
		target.draw(live, states);
		states.transform.translate(live.getLocalBounds().width, 0);
	}
}

unsigned int Statistics::getLives() const{
	return lives;
}

void Statistics::setLives(unsigned int lives){
	this->lives = lives;
}

unsigned int Statistics::getPoints() const{
	return points;
}

void Statistics::setPoints(unsigned int points){
	if(this->points < 10000 && points >= 10000)
		setLives(getLives() + 1);
	this->points = points;
	pointsText.setString(std::to_string(points));
}

unsigned int Statistics::getHighScore() const{
	return highScore;
}

void Statistics::setHighScore(unsigned int highScore){
	this->highScore = highScore;
	highScoreText.setString(std::to_string(highScore));
}

unsigned int Statistics::getLevel() const{
	return level;
}

void Statistics::setLevel(unsigned int level){
	Statistics::level = level;
	levelText.setString(std::to_string(level));
}

unsigned int Statistics::getGhostsEatenStreak() const{
	return ghostsEatenStreak;
}

unsigned int Statistics::getPointsEaten() const{
	return pointsEaten;
}

unsigned int Statistics::getPointsTotal() const{
	return pointsTotal;
}

Statistics::Statistics(){
	pointsText.setFont(AssetManager::get().font);
	highScoreText.setFont(AssetManager::get().font);
	levelText.setFont(AssetManager::get().font);
	
	pointsText.setCharacterSize(12);
	highScoreText.setCharacterSize(12);
	levelText.setCharacterSize(12);
	
	pointsText.setPosition(120, -24);
	
	live.setPosition(60, 396);
	
	setPoints(0);
	setHighScore(0);
	setLevel(1);
	setLives(3);
	live.setTexture(AssetManager::get().pacman.left.getFrame(0));
}
