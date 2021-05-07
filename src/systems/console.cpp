#include "console.hpp"
#include <iostream>

#ifdef WIN32
#include <windows.h>
#endif

Signal<Message> message;

void Console::onNotify(const Message& event){
	if(types.count(event.type) == 1){
		if(event.type == Message::Debug)
			std::clog << "\033[1;34mDEBUG: " + event.getMessage() << "\033[0m\n";
		if(event.type == Message::Error)
			std::cerr << "\033[1;31mERROR: " + event.getMessage() << "\033[0m\n";
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
#ifdef WIN32 // we need this only when on windows, because on unix-like systems it is enabled by default
	HANDLE stdo = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(stdo, &dwMode);
	dwMode |= 0x0004;
	SetConsoleMode(stdo, dwMode);

	HANDLE stde = GetStdHandle(STD_ERROR_HANDLE);
	dwMode = 0;
	GetConsoleMode(stde, &dwMode);
	dwMode |= 0x0004;
	SetConsoleMode(stde, dwMode);
#endif

	message.addListener(this);
	gameEventSignal.addListener(this);
}

Console::~Console(){
	message.removeListener(this);
	gameEventSignal.removeListener(this);
}