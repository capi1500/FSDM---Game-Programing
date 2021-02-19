//
// Created by Kacper on 04/12/2020.
//

#include <iostream>
#include "state.hpp"

void State::draw(sf::RenderWindow& window){
	for(Object* p : m_objects)
		p->draw(window);
}

void State::update(const sf::Time& time){
	for(Object* p : m_objects)
		p->update(time);
}

void State::input(const sf::Event& event){
	for(Object* p : m_objects)
		p->input(event);
}

bool State::isDelete() const{
	return m_delete;
}

void State::setDelete(bool _delete){
	m_delete = _delete;
}

State::State(){
	m_delete = false;
}

State::~State(){
	for(Object* p : m_objects){
		delete p;
		p = nullptr;
	}
}
