//
// Created by Kacper on 11/12/2020.
//

#include <common.hpp>
#include <iostream>
#include "counter.hpp"

void Counter::draw(sf::RenderWindow& window){
	window.draw(m_text);
}

void Counter::update(const sf::Time& time){

}

void Counter::input(const sf::Event& input){

}

void Counter::restart(){

}

void Counter::onNotify(const Event& event){
	if(event.type == Event::BallOutOfScreen){
		if(event.ballOut.isLeftPlayer != m_isLeft){
			m_counter++;
			m_text.setString(std::to_string(m_counter));
		}
	}
}

Counter::Counter(bool isLeft, int posx, int posy){
	m_isLeft = isLeft;
	m_counter = 0;
	startPosition = sf::Vector2f(posx, posy);
	m_text.setString("0");
	m_text.setFont(font);
	m_text.setCharacterSize(30);
	m_text.setPosition(posx, posy);
	eventQueue.addListener(this);
}

Counter::~Counter(){
	eventQueue.removeListener(this);
}
