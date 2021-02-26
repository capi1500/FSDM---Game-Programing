//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_SIGNAL_HPP
#define PROGRAMOWANIEGIER_SIGNAL_HPP

#include <queue>
#include <set>
#include "event.hpp"
#include "listener.hpp"

class Signal{
	private:
		std::queue<Event> m_events;
		std::set<Listener*> m_listeners;
	public:
		void addListener(Listener* listener);
		void removeListener(Listener* listener);
		
		void notify(const Event& event);
		
		void handleEvents();
};

#endif //PROGRAMOWANIEGIER_SIGNAL_HPP
