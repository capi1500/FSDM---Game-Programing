//
// Created by Kacper on 11/12/2020.
//

#include <Utils/circle.hpp>
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
	if(shift != {0, 0}){
		m_rect.move(shift);
		for(auto p : m_shapes)
			p->move();
	}
}

void Paddle::input(const sf::Event& input){

}

Paddle::Paddle(sf::Keyboard::Key up, sf::Keyboard::Key down, int posx, int posy, int sizex, int sizey) : m_up(up), m_down(down){
	m_rect.setSize(sf::Vector2f(sizex, sizey));
	m_rect.setPosition(posx, posy);
	m_velocity = 50;
	
	m_shapes.push_back(new Circle(radious, sf::Vector2f(posx, posy)));
	m_shapes.push_back(new Circle(radious, sf::Vector2f(posx, posy + sixey)));
	m_shapes.push_back(new Circle(radious, sf::Vector2f(posx + sizex, posy)));
	m_shapes.push_back(new Circle(radious, sf::Vector2f(posx + sizex, posy + sizey)));/*
	m_shapes.push_back(new Segment(sf::Vector2f(posx, posy - radious), sf::Vector2f(posx + sizex, posy - radious)));
	m_shapes.push_back(new Segment(sf::Vector2f(posx, posy + sizey + radious), sf::Vector2f(posx + sizex, posy + sizey + radious)));
	m_shapes.push_back(new Segment(sf::Vector2f(posx - radious, posy), sf::Vector2f(posx - radious, posy + sizey)));
	m_shapes.push_back(new Segment(sf::Vector2f(posx + sizex + radious, posy), sf::Vector2f(posx + sizex + radious, posy + sizey)));*/
	m_shapes.push_back(new Rectangle(sf::FloatRect(posx, posy - radious, sizex, sizey + 2 * radious)));
	m_shapes.push_back(new Rectangle(sf::FloatRect(posx - radious, posy, sizex + 2 * radious, sizey)));
}

std::tuple<bool, Line> Paddle::findBounce(const sf::Vector2f& o, const sf::Vector2f& n){
	Segment shift = Segment(o, n);
	
	sf::Vector2f closest = n;
	Line bounceLine = Line(0, 0, 0);
	double minDistance = distance(o, n);
	
	for(auto p : m_shapes){
		if(p->pointInside(n) and p->isCrossLine(shift)){
			std::vector<sf::Vector2f> t = p->crossLine(shift);
			for(auto& x : t){
				if(distance(o, x) < minDistance){
					minDistance = distance(o, x);
					closest = x;
				}
			}
		}
	}
	return {closest = n, bounceLine};
}
