#include "finiteStateMachine.hpp"
#include <systems/console.hpp>

FiniteState* FiniteStateMachine::get(){
	handleEvents();
	if(states.empty()){
		message.notify(Message("No states in Finite State Machine", Message::Error));
		return nullptr;
	}
	return states.top();
}

void FiniteStateMachine::add(FiniteState* state){
	FiniteStateEvent event;
	event.type = FiniteStateEvent::Add;
	event.add.state = state;
	notify(event);
}

void FiniteStateMachine::pop(unsigned int count){
	FiniteStateEvent event;
	event.type = FiniteStateEvent::Pop;
	event.pop.count = count;
	notify(event);
}

void FiniteStateMachine::replace(FiniteState* state){
	FiniteStateEvent event;
	event.type = FiniteStateEvent::Replace;
	event.replace.state = state;
	notify(event);
}

void FiniteStateMachine::clear(){
	FiniteStateEvent event;
	event.type = FiniteStateEvent::Clear;
	notify(event);
}

void FiniteStateMachine::onNotify(const FiniteStateEvent& event){
	if(event.type == FiniteStateEvent::Add){
		if(!states.empty())
			states.top()->setActive(false);
		states.push(event.add.state);
		states.top()->setActive(true);
	}
	else if(event.type == FiniteStateEvent::Pop){
		for(unsigned i = 0; i < event.pop.count; i++){
			if(states.empty())
				break;
			delete states.top();
			states.pop();
		}
	}
	else if(event.type == FiniteStateEvent::Replace){
		if(states.empty()){
			message.notify(Message("No states in Finite State Machine", Message::Error));
			break;
		}
		delete states.top();
		states.pop();
		states.push(event.add.state);
		states.top()->setActive(true);
	}
	else if(event.type == FiniteStateEvent::Clear){
		while(!states.empty()){
			delete states.top();
			states.pop();
		}
	}
}

FiniteStateMachine::FiniteStateMachine(){
	addListener(this);
}

FiniteStateMachine::~FiniteStateMachine(){
	removeListener(this);
}
