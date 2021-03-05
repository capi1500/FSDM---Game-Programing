#ifndef PROGRAMOWANIEGIER_MESSAGE_HPP
#define PROGRAMOWANIEGIER_MESSAGE_HPP

#include <string>

class Message{
	private:
		std::string message;
	public:
		enum Type{
			Debug,
			Error
		};
		
		Type type;
		
		const std::string& getMessage() const;
		
		Message(const std::string& message, Type type);
};

#endif //PROGRAMOWANIEGIER_MESSAGE_HPP
