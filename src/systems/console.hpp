#ifndef PROGRAMOWANIEGIER_CONSOLE_HPP
#define PROGRAMOWANIEGIER_CONSOLE_HPP

#include <signal/listener.hpp>
#include <signal/signal.hpp>
#include <misc/message.hpp>
#include <misc/singleton.hpp>
#include <set>

class Console : public Singleton<Console>, public Listener<Message>{
	private:
		std::set<Message::Type> types;
	protected:
		void init() override;
	public:
		Console(Singleton<Console>& singleton);
		
		void listenType(Message::Type type);
		void onNotify(const Message& event) override;
		virtual ~Console();
};

extern Signal<Message> message;

#endif //PROGRAMOWANIEGIER_CONSOLE_HPP
