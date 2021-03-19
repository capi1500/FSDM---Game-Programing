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

void Console::listenType(Message::Type type){
	types.insert(type);
}

void Console::init(){
	message.addListener(this);
}

Console::~Console(){
	message.removeListener(this);
}
