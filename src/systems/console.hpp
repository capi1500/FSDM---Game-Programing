#ifndef PROGRAMOWANIEGIER_CONSOLE_HPP
#define PROGRAMOWANIEGIER_CONSOLE_HPP

#include <signal/listener.hpp>
#include <signal/signal.hpp>
#include <misc/message.hpp>
#include <misc/singleton.hpp>
#include <set>
#include <gameEvent.hpp>

class Console : public Listener<Message>, public Listener<GameEvent>{
	private:
		std::set<Message::Type> types;
	public:
		void listenType(Message::Type type);
		void onNotify(const Message& event) override;
		
		void onNotify(const GameEvent& event) override;
		
		Console();
		virtual ~Console();
};

extern Signal<Message> message;

#endif //PROGRAMOWANIEGIER_CONSOLE_HPP
