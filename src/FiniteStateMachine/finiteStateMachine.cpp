//
// Created by Kacper on 04/12/2020.
//

#include <iostream>
#include "finiteStateMachine.hpp"

void FiniteStateMachine::updateStates(){
	while(!m_stateMachine.empty() && m_toDelete != 0){
		delete m_stateMachine.top();
		m_stateMachine.pop();
		m_toDelete--;
	}
	while(!m_toAdd.empty()){
		m_stateMachine.push(m_toAdd.front());
		m_toAdd.pop();
	}
}

State* FiniteStateMachine::getState(){
	updateStates();
	return m_stateMachine.top();
}

void FiniteStateMachine::addState(State* state){
	m_toAdd.push(state);
}

void FiniteStateMachine::removeState(unsigned count){
	m_toDelete += count;
}

void FiniteStateMachine::destroy(){
	while(!m_stateMachine.empty()){
		delete m_stateMachine.top();
		m_stateMachine.pop();
	}
	while(!m_toAdd.empty()){
		delete m_toAdd.front();
		m_toAdd.pop();
	}
}
