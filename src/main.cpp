#include <FiniteStateMachine/finiteStateMachine.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Objects/ball.hpp>
#include <Objects/paddle.hpp>
#include <Utils/function.hpp>

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

void Game::checkBounce(){
	Ball* ball = dynamic_cast<Ball*>(m_objects[0]);
	sf::Vector2<long double> n = ball->getPosition(), o = ball->getOldPosition();
	long double r = ball->getRadius();
	Function up({o.x, o.y - r}, {n.x, n.y - r}), down({o.x, o.y + r}, {n.x, n.y + r}), left({o.x - r, o.y}, {n.x - r, n.y}), right({o.x + r, o.y}, {n.x + r, n.y});
	
	Paddle* p1 = dynamic_cast<Paddle*>(m_objects[1]);
	Paddle* p2 = dynamic_cast<Paddle*>(m_objects[2]);
	
	
}

void Game::update(const sf::Time& time){
	State::update(time);
	checkBounce();
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