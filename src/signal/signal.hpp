#ifndef PROGRAMOWANIEGIER_SIGNAL_HPP
#define PROGRAMOWANIEGIER_SIGNAL_HPP

#include <queue>
#include <set>
#include "listener.hpp"

template<typename T>
class Signal{
	private:
		std::queue<T> m_events;
		std::set<Listener<T>*> m_listeners;
	public:
		void addListener(Listener<T>* listener){
			m_listeners.insert(listener);
		}
		void removeListener(Listener<T>* listener){
			m_listeners.erase(m_listeners.find(listener));
		}
		
		void notify(const T& event){
			m_events.push(event);
		}
		
		void handleEvents(){
			T* event;
			while(!m_events.empty()){
				event = &m_events.front();
				for(auto l : m_listeners){
					l->onNotify(*event);
				}
				m_events.pop();
			}
		}
	
};

#endif //PROGRAMOWANIEGIER_SIGNAL_HPP
