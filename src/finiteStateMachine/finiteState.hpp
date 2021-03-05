#ifndef PROGRAMOWANIEGIER_FINITESTATE_HPP
#define PROGRAMOWANIEGIER_FINITESTATE_HPP

class FiniteStateMachine;

class FiniteState{
	private:
		FiniteStateMachine& fsm;
		bool active;
	public:
		bool isActive() const;
		void setActive(bool active);
		
		FiniteState(FiniteStateMachine& fsm);
		virtual ~FiniteState() = default;
};

#endif //PROGRAMOWANIEGIER_FINITESTATE_HPP
