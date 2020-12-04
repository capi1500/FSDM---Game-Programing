#include <FiniteStateMachine/finiteStateMachine.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

FiniteStateMachine machine;

class MainMenu : public State{
	public:
		void draw() override{
			State::draw();
			std::cout << "main menu\n";
		}
		
		void input(const sf::Event& event) override;
};

class Game : public State{
	public:
		void draw() override{
			State::draw();
			std::cout << "game\n";
		}
		
		void input(const sf::Event& event) override;
};

void MainMenu::input(const sf::Event& event){
	State::input(event);
	if(event.type == sf::Event::KeyPressed){
		if(event.key.code == sf::Keyboard::Num1){
			machine.addState(new Game);
		}
		if(event.key.code == sf::Keyboard::Backspace){
			machine.removeState();
		}
	}
}

void Game::input(const sf::Event& event){
	State::input(event);
	if(event.type == sf::Event::KeyPressed){
		if(event.key.code == sf::Keyboard::Num2){
			machine.addState(new MainMenu);
		}
		if(event.key.code == sf::Keyboard::Backspace){
			machine.removeState();
		}
	}
}

int main(){
	machine.addState(new MainMenu);
	State* state;
	
	sf::RenderWindow window(sf::VideoMode(500, 500), "pong");
	sf::Event event;
	while (window.isOpen()){
		state = machine.getState();
		while (window.pollEvent(event)){
			state->input(event);
			if(event.type == sf::Event::Closed)
				window.close();
		}
		
		state->update(sf::seconds(0));
		
		window.clear();
		state->draw();
		window.display();
	}
}