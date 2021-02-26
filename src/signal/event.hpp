//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_EVENT_HPP
#define PROGRAMOWANIEGIER_EVENT_HPP

class Event{
	public:
		enum EventType{
			BallOutOfScreen,
			GameOver
		};
		
		EventType type;
		
		struct BallOut{
			bool isLeftPlayer;
		};
		
		union{
			BallOut ballOut;
		};
};

#endif //PROGRAMOWANIEGIER_EVENT_HPP
