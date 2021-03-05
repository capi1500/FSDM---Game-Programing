

#include "message.hpp"

Message::Message(const std::string& message, Message::Type type) : message(message), type(type){
}

const std::string& Message::getMessage() const{
	return message;
}
