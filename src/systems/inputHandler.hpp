#ifndef PROGRAMOWANIEGIER_INPUTHANDLER_HPP
#define PROGRAMOWANIEGIER_INPUTHANDLER_HPP

#include <signal/signal.hpp>
#include <misc/singleton.hpp>
#include <SFML/Window.hpp>

class InputHandler : public Singleton<InputHandler>, public Signal<sf::Event>{
	private:
		sf::Window* window;
	public:
		void registerWindow(sf::Window* window);
		void handleEvents();
};

#endif //PROGRAMOWANIEGIER_INPUTHANDLER_HPP
