#include "finiteState.hpp"
#include "finiteStateMachine.hpp"

bool FiniteState::isActive() const{
	return active;
}

void FiniteState::setActive(bool active){
	FiniteState::active = active;
}

FiniteState::FiniteState(FiniteStateMachine& fsm) : fsm(fsm){
	setActive(false);
}
