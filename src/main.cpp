#include <FiniteStateMachine/finiteStateMachine.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Objects/ball.hpp>
#include <Objects/paddle.hpp>
#include <Utils/line.hpp>
#include <Utils/segment.hpp>
#include <Utils/rectangle.hpp>

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
	
	/// DEBUG
	auto printVec = [] (const sf::Vector2f& v) {
		std::cout << "{" << v.x << ", " << v.y << "}";
	};
	
	std::cout << "Checking bounce: ";
	printVec(o);
	std::cout << " -> ";
	printVec(n);
	std::cout << "\n";
	/// END DEBUG
	
	bool bounced;
	Line line;
	for(int i = 1; i < 5; i++){
		 std::tie(bounced, line) = dynamic_cast<Paddle*>(m_objects[i])->findBounce(o, n);
		 if(bounced){
		 	std::cout << "\tBouncing from line ";
		 	line.print();
		 	std::cout << "\n";
		 	ball->bounce(line);
		 	//throw -1;
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
	
	window.create(sf::VideoMode(500, 500), "pong");
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
		}
		
		state->update(time);
		
		window.clear();
		state->draw(window);
		window.display();
	}
}