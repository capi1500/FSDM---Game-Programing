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
		m_rect.move(shift);
		for(auto p : m_shapes)
			p->move(shift);
	}
}

void Paddle::input(const sf::Event& input){

}

Paddle::Paddle(sf::Keyboard::Key up, sf::Keyboard::Key down, int posx, int posy, int sizex, int sizey) : m_up(up), m_down(down){
	m_rect.setSize(sf::Vector2f(sizex, sizey));
	m_rect.setPosition(posx, posy);
	m_velocity = 50;
	
	m_shapes.push_back(new Circle(radious, sf::Vector2f(posx, posy)));
	m_shapes.push_back(new Circle(radious, sf::Vector2f(posx, posy + sizey)));
	m_shapes.push_back(new Circle(radious, sf::Vector2f(posx + sizex, posy)));
	m_shapes.push_back(new Circle(radious, sf::Vector2f(posx + sizex, posy + sizey)));
	m_shapes.push_back(new Rectangle(sf::FloatRect(posx, posy - radious, sizex, sizey + 2 * radious)));
	m_shapes.push_back(new Rectangle(sf::FloatRect(posx - radious, posy, sizex + 2 * radious, sizey)));
}

std::tuple<bool, Line> Paddle::findBounce(const sf::Vector2f& o, const sf::Vector2f& n){
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
	
	return std::make_tuple(closest != n, bounceLine);
}
