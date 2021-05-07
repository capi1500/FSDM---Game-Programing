#include "console.hpp"
#include <iostream>

Signal<Message> message;

void Console::onNotify(const Message& event){
	if(types.count(event.type) == 1){
		if(event.type == Message::Debug)
			std::clog << "DEBUG: " + event.getMessage() << "\n";
		if(event.type == Message::Error)
			std::cerr << "ERROR: " + event.getMessage() << "\n";
	}
}

void Console::onNotify(const GameEvent& event){
	if(event.type == GameEvent::PacmanMove)
		message.notify(Message("pacman moved (" + std::to_string(event.pacmanMove.position.x) + ", " + std::to_string(event.pacmanMove.position.y) + ")", Message::Debug));
	else if(event.type == GameEvent::BigPointEaten)
		message.notify(Message("big point eaten", Message::Debug));
}

void Console::listenType(Message::Type type){
	types.insert(type);
}

Console::Console(){
	message.addListener(this);
	gameEventSignal.addListener(this);
}

Console::~Console(){
	message.removeListener(this);
	gameEventSignal.removeListener(this);
}