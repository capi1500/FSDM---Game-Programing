#ifndef PROGRAMOWANIEGIER_FINITESTATEEVENT_HPP
#define PROGRAMOWANIEGIER_FINITESTATEEVENT_HPP

#include "finiteState.hpp"

class FiniteStateEvent{
	public:
		enum Type{
			Add,
			Pop,
			Replace,
			Clear
		};
		
		Type type;
		
		struct AddEvent{
			FiniteState* state;
		};
		
		struct PopEvent{
			unsigned count;
		};
		
		struct ReplaceEvent{
			FiniteState* state;
		};
		
		union{
			AddEvent add;
			PopEvent pop;
			ReplaceEvent replace;
		};
};

#endif //PROGRAMOWANIEGIER_FINITESTATEEVENT_HPP
