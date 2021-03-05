#ifndef PROGRAMOWANIEGIER_FINITESTATEMACHINE_HPP
#define PROGRAMOWANIEGIER_FINITESTATEMACHINE_HPP

#include <stack>
#include <signal/signal.hpp>
#include "finiteState.hpp"
#include "finiteStateEvent.hpp"

class FiniteStateMachine : public Signal<FiniteStateEvent>, public Listener<FiniteStateEvent>{
	private:
		std::stack<FiniteState*> states;
	public:
		void onNotify(const FiniteStateEvent& event) override;
		
		void add(FiniteState* state);
		void pop(unsigned count = 1);
		void replace(FiniteState* state);
		void clear();
		
		FiniteState* get();
		
		FiniteStateMachine();
		~FiniteStateMachine();
};

#endif //PROGRAMOWANIEGIER_FINITESTATEMACHINE_HPP
