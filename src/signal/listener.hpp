//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_LISTENER_HPP
#define PROGRAMOWANIEGIER_LISTENER_HPP

#include "event.hpp"

class Listener{
	public:
		virtual void onNotify(const Event& event) = 0;
		virtual ~Listener() = default;
};

#endif //PROGRAMOWANIEGIER_LISTENER_HPP
