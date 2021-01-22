//
// Created by Kacper on 11/12/2020.
//

#include <Utils/circle.hpp>
#include <iostream>
#include "paddle.hpp"
#include "common.hpp"

void Paddle::draw(sf::RenderWindow& window){
	window.draw(m_rect);
}

void Paddle::update(const sf::Time& time){
	sf::Vector2f shift = {0, 0};
	if(sf::Keyboard::isKeyPressed(m_up)){
		shift = {0, -m_velocity * time.asSeconds()};
	}
	if(sf::Keyboard::isKeyPressed(m_down)){
		shift = {0, m_velocity * time.asSeconds()};
	}
	if(shift != sf::Vector2f(0, 0)){
		if(shift.y + m_rect.getPosition().y < 0)
			shift.y = -m_rect.getPosition().y;
		if(shift.y + m_rect.getPosition().y + m_rect.getSize().y > windowSizeY)
			shift.y = windowSizeY - m_rect.getPosition().y - m_rect.getSize().y;
		m_rect.move(shift);
		for(auto p : m_shapes)
			p->move(shift);
	}
}

void Paddle::input(const sf::Event& input){

}

Paddle::Paddle(sf::Keyboard::Key up, sf::Keyboard::Key down, int posx, int posy, int sizex, int sizey) : m_up(up), m_down(down){
	m_velocity = 200;
	startPosition = sf::Vector2f(posx, posy);
	m_size = sf::Vector2f(sizex, sizey);
	
	restart();
}

std::tuple<bool, bool, Line> Paddle::findBounce(const sf::Vector2f& o, const sf::Vector2f& n){
	Segment shift = Segment(o, n);
	
	sf::Vector2f closest = n;
	Line bounceLine = Line(0, 0, 0);
	double minDistance = 1000000000;
	
	
	for(auto p : m_shapes){
		if(p->pointInside(n) and p->isCrossLine(shift)){
			std::vector<std::pair<sf::Vector2f, Line>> t = p->crossLine(shift);
			for(auto& x : t){
				if(distance(o, x.first) < minDistance){
					minDistance = distance(o, x.first);
					closest = x.first;
					bounceLine = x.second;
				}
			}
		}
	}
	
	return std::make_tuple(closest != n, m_up != sf::Keyboard::KeyCount, bounceLine);
}

void Paddle::restart(){
	m_rect.setSize(m_size);
	m_rect.setPosition(startPosition);
	
	m_shapes.clear();
	m_shapes.push_back(new Circle(radious, sf::Vector2f(startPosition.x, startPosition.y)));
	m_shapes.push_back(new Circle(radious, sf::Vector2f(startPosition.x, startPosition.y + m_size.y)));
	m_shapes.push_back(new Circle(radious, sf::Vector2f(startPosition.x + m_size.x, startPosition.y)));
	m_shapes.push_back(new Circle(radious, sf::Vector2f(startPosition.x + m_size.x, startPosition.y + m_size.y)));
	m_shapes.push_back(new Rectangle(sf::FloatRect(startPosition.x, startPosition.y - radious, m_size.x, m_size.y + 2 * radious)));
	m_shapes.push_back(new Rectangle(sf::FloatRect(startPosition.x - radious, startPosition.y, m_size.x + 2 * radious, m_size.y)));
}
