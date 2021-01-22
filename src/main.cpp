#include <FiniteStateMachine/finiteStateMachine.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Objects/ball.hpp>
#include <Objects/paddle.hpp>
#include <Utils/line.hpp>
#include <Utils/segment.hpp>
#include <Utils/rectangle.hpp>
#include "common.hpp"

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
	private:
		void checkBounce();
	public:
		void draw(sf::RenderWindow& window) override{
			State::draw(window);
			//std::cout << "game\n";
		}
		
		void input(const sf::Event& event) override;
		
		void update(const sf::Time& time) override;
		
		Game(){
			int x = window.getSize().x / 10;
			int y = window.getSize().y / 10;
			int sizex = radious;
			int sizey = window.getSize().y / 3;
			m_objects.push_back(new Ball(window.getSize()));
			m_objects.push_back(new Paddle(sf::Keyboard::W, sf::Keyboard::S, 3 * sizex, (window.getSize().y - sizey) / 2, sizex, sizey));
			m_objects.push_back(new Paddle(sf::Keyboard::Up, sf::Keyboard::Down, window.getSize().x - 4 * sizex, (window.getSize().y - sizey) / 2, sizex, sizey));
			m_objects.push_back(new Paddle(sf::Keyboard::KeyCount, sf::Keyboard::KeyCount, -100, -100, window.getSize().x + 200, 100));
			m_objects.push_back(new Paddle(sf::Keyboard::KeyCount, sf::Keyboard::KeyCount, -100, window.getSize().y, window.getSize().x + 200, 100));
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

void Game::checkBounce(){
	Ball* ball = dynamic_cast<Ball*>(m_objects[0]);
	sf::Vector2f n = ball->getPosition(), o = ball->getOldPosition();
	
	bool bounced, speedup;
	Line line;
	for(int i = 1; i < 5; i++){
		 std::tie(bounced, speedup, line) = dynamic_cast<Paddle*>(m_objects[i])->findBounce(o, n);
		 if(bounced){
		 	ball->bounce(line, speedup);
		 	checkBounce();
		 	return;
		 }
	}
	
}

void Game::update(const sf::Time& time){
	State::update(time);
	checkBounce();
}

int main(){
	srand(time(NULL));
	
	machine.addState(new MainMenu);
	State* state;
	
	window.create(sf::VideoMode(500, 500), "pong", sf::Style::Fullscreen);
	windowSizeX = window.getSize().x;
	windowSizeY = window.getSize().y;
	
	window.setFramerateLimit(60);
	
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
			if(event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
				window.close();
		}
		
		state->update(time);
		
		window.clear();
		state->draw(window);
		window.display();
	}
}