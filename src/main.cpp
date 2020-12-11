#include <FiniteStateMachine/finiteStateMachine.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Objects/ball.hpp>
#include <Objects/paddle.hpp>

sf::RenderWindow window;
FiniteStateMachine machine;

class MainMenu : public State{
	public:
		void draw(sf::RenderWindow& window) override{
			State::draw(window);
			//std::cout << "main menu\n";
		}
		
		void input(const sf::Event& event) override;
};

class Game : public State{
	public:
		void draw(sf::RenderWindow& window) override{
			State::draw(window);
			//std::cout << "game\n";
		}
		
		void input(const sf::Event& event) override;
		
		Game(){
			int x = window.getSize().x / 10;
			int y = window.getSize().y / 10;
			m_objects.push_back(new Ball(window.getSize()));
			m_objects.push_back(new Paddle(sf::Keyboard::W, sf::Keyboard::S, x, y, x, y * 8));
			m_objects.push_back(new Paddle(sf::Keyboard::Up, sf::Keyboard::Down, x * 8, y, x, y * 8));
		}
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
	srand(time(NULL));
	
	machine.addState(new MainMenu);
	State* state;
	
	window.create(sf::VideoMode(500, 500), "pong");
	sf::Event event;
	
	sf::Clock clock;
	sf::Time time;
	while (window.isOpen()){
		time = clock.restart();
		
		state = machine.getState();
		while (window.pollEvent(event)){
			state->input(event);
			if(event.type == sf::Event::Closed)
				window.close();
		}
		
		state->update(time);
		
		window.clear();
		state->draw(window);
		window.display();
	}
}