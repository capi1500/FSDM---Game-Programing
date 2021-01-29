//
// Created by Kacper on 11/12/2020.
//

#include <iostream>
#include "signal.hpp"

void Signal::addListener(Listener* listener){
	m_listeners.insert(listener);
}

void Signal::removeListener(Listener* listener){
	m_listeners.erase(listener);
}

void Signal::notify(const Event& event){
	m_events.push(event);
}

void Signal::handleEvents(){
	Event event;
	while(!m_events.empty()){
		event = m_events.front();
		m_events.pop();
		for(auto l : m_listeners){
			l->onNotify(event);
		}
	}
}
