//
// Created by Kacper on 28/05/2021.
//

#ifndef PROGRAMOWANIEGIER_SETTINGS_HPP
#define PROGRAMOWANIEGIER_SETTINGS_HPP

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "gameEvent.hpp"

class Statistics : public Listener<GameEvent>, public sf::Drawable{
	private:
		unsigned lives;
		unsigned points;
		unsigned highScore;
		unsigned level;
		
		sf::Sprite live;
		sf::Text pointsText;
		sf::Text highScoreText;
		sf::Text levelText;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void onNotify(const GameEvent& event) override;
		
		unsigned int getLives() const;
		void setLives(unsigned int lives);
		unsigned int getPoints() const;
		void setPoints(unsigned int points);
		unsigned int getHighScore() const;
		void setHighScore(unsigned int highScore);
		unsigned int getLevel() const;
		void setLevel(unsigned int level);
		
		Statistics();
};

#endif //PROGRAMOWANIEGIER_SETTINGS_HPP
