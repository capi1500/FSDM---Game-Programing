//
// Created by Kacper on 11/12/2020.
//

#include <Utils/circle.hpp>
#include <iostream>
#include "paddle.hpp"
#include "common.hpp"

void Paddle::draw(sf::RenderWindow& window){
	window.draw(m_rect);
	
	// DEBUG
	window.draw(c1);
	window.draw(c2);
	window.draw(c3);
	window.draw(c4);
	window.draw(r1);
	window.draw(r2);
	// END
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
	
	// DEBUG
	c1.move(shift);
	c2.move(shift);
	c3.move(shift);
	c4.move(shift);
	r1.move(shift);
	r2.move(shift);
	// END
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
	
	// DEBUG
	c1.setRadius(radious);
	c2.setRadius(radious);
	c3.setRadius(radious);
	c4.setRadius(radious);
	c1.setPosition(posx - radious, posy - radious);
	c2.setPosition(posx - radious, posy - radious + sizey);
	c3.setPosition(posx - radious + sizex, posy - radious);
	c4.setPosition(posx - radious + sizex, posy - radious + sizey);
	r1.setPosition(posx, posy - radious);
	r2.setPosition(posx - radious, posy);
	r1.setSize(sf::Vector2f(sizex, sizey + 2 * radious));
	r2.setSize(sf::Vector2f(sizex + 2 * radious, sizey));
	
	c1.setFillColor(sf::Color(0, 255, 0, 127));
	c2.setFillColor(sf::Color(0, 255, 0, 127));
	c3.setFillColor(sf::Color(0, 255, 0, 127));
	c4.setFillColor(sf::Color(0, 255, 0, 127));
	r1.setFillColor(sf::Color(255, 0, 0, 127));
	r2.setFillColor(sf::Color(255, 0, 0, 127));
	// END
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
