//
// Created by Kacper on 11/12/2020.
//

#include <cmath>
#include <iostream>
#include <Utils/vector.hpp>
#include <common.hpp>
#include "ball.hpp"

void Ball::draw(sf::RenderWindow& window){
	window.draw(m_circle);
}

void Ball::update(const sf::Time& time){
	m_oldPosition = {getPosition().x, getPosition().y};
	m_circle.move(m_velocity * cos(m_angle) * time.asSeconds(), m_velocity * sin(m_angle) * time.asSeconds());
	
	if(m_oldPosition.x < 0 or m_oldPosition.x > windowSizeX){
	
	}
}

void Ball::input(const sf::Event& input){

}

void Ball::bounce(const Line& line, const bool speedup){
	sf::Vector2f o = getOldPosition(), n = getPosition(), np, c = line.crossLine(Line(o, n))[0].first;
	
	Vector u = Vector(c, n), dir = Vector(-line.getB(), line.getA()).normalize();
	long double r = dir ^ u;
	dir *= r;
	Vector shift = -u + dir;
	np = (Vector(n) + shift * 2).toVector2f();
	
	m_oldPosition = c;
	setCenter(np);
	
	u = Vector(c, np);
	m_angle = atan2(u.y, u.x);
	
	if(speedup)
		m_velocity = m_velocity * 11 / 10;
}

Ball::Ball(sf::Vector2u windowSize){
	m_circle.setRadius(radious);
	startPosition = {windowSize.x / 2.f, windowSize.y / 2.f};
	restart();
}

void Ball::setCenter(const sf::Vector2f& p){
	m_circle.setPosition(p.x - getRadius(), p.y - getRadius());
}

sf::Vector2f Ball::getPosition() const{
	return m_circle.getPosition() + sf::Vector2f(getRadius(), getRadius());
}

const sf::Vector2f& Ball::getOldPosition() const{
	return m_oldPosition;
}

float Ball::getRadius() const{
	return m_circle.getRadius();
}

void Ball::restart(){
	setCenter(startPosition);
	m_velocity = 200;
	m_angle = (rand() % static_cast<int>(2 * M_PI * 1000)) / 1000.0;
}
