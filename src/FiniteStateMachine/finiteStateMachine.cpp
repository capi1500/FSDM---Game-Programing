//
// Created by Kacper on 04/12/2020.
//

#include <iostream>
#include "finiteStateMachine.hpp"

void FiniteStateMachine::updateStates(){
	while(!m_toAdd.empty()){
		m_stateMachine.push(m_toAdd.front());
		m_toAdd.pop();
	}
	while(!m_stateMachine.empty() and m_stateMachine.top()->isDelete()){
		delete m_stateMachine.top();
		m_stateMachine.pop();
	}
}

State* FiniteStateMachine::getState(){
	updateStates();
	return m_stateMachine.top();
}

void FiniteStateMachine::addState(State* state){
	m_toAdd.push(state);
}

void FiniteStateMachine::removeState(){
	m_stateMachine.top()->setDelete(true);
}

FiniteStateMachine::~FiniteStateMachine(){
	while(!m_stateMachine.empty()){
		delete m_stateMachine.top();
		m_stateMachine.pop();
	}
}
