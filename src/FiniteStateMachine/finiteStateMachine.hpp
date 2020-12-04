//
// Created by Kacper on 04/12/2020.
//

#ifndef PROGRAMOWANIEGIER_FINITESTATEMACHINE_HPP
#define PROGRAMOWANIEGIER_FINITESTATEMACHINE_HPP

#include <stack>
#include <queue>
#include "state.hpp"

class FiniteStateMachine{
	private:
		std::stack<State*> m_stateMachine;
		std::queue<State*> m_toAdd;
		
		void updateStates();
	public:
		State* getState();
		void addState(State* state);
		void removeState();
		
		virtual ~FiniteStateMachine();
};

#endif //PROGRAMOWANIEGIER_FINITESTATEMACHINE_HPP
