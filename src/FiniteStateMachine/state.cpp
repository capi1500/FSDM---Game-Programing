//
// Created by Kacper on 04/12/2020.
//

#include <iostream>
#include "state.hpp"

void State::draw(){
	std::cout << "STATE\n";
}

void State::update(const sf::Time& time){}

void State::input(const sf::Event& event){}

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
}
