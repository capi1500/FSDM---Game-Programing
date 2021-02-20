#include <FiniteStateMachine/finiteStateMachine.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Objects/ball.hpp>
#include <Objects/paddle.hpp>
#include <Utils/line.hpp>
#include <Utils/segment.hpp>
#include <Utils/rectangle.hpp>
#include <Signal/listener.hpp>
#include <Signal/signal.hpp>
#include <Objects/counter.hpp>
#include <Objects/button.hpp>
#include <Objects/label.hpp>
#include "common.hpp"

class MainMenu : public State{
	public:
		void draw(sf::RenderWindow& window) override{
			State::draw(window);
		}
		
		void input(const sf::Event& event) override;
		
		MainMenu();
};

class Game : public State, public Listener{
	private:
		void checkBounce();
	public:
		void onNotify(const Event& event) override;
		
		void draw(sf::RenderWindow& window) override{
			State::draw(window);
		}
		
		void input(const sf::Event& event) override;
		
		void update(const sf::Time& time) override;
		
		Game(){
			window.setMouseCursorVisible(false);
			eventQueue.addListener(this);
			int sizex = radious;
			int sizey = window.getSize().y / 3;
			m_objects.push_back(new Ball(window.getSize()));
			m_objects.push_back(new Paddle(sf::Keyboard::W, sf::Keyboard::S, 3 * sizex, (window.getSize().y - sizey) / 2, sizex, sizey));
			m_objects.push_back(new Paddle(sf::Keyboard::Up, sf::Keyboard::Down, window.getSize().x - 4 * sizex, (window.getSize().y - sizey) / 2, sizex, sizey));
			m_objects.push_back(new Paddle(sf::Keyboard::KeyCount, sf::Keyboard::KeyCount, -100, -100, window.getSize().x + 200, 100));
			m_objects.push_back(new Paddle(sf::Keyboard::KeyCount, sf::Keyboard::KeyCount, -100, window.getSize().y, window.getSize().x + 200, 100));
			m_objects.push_back(new Counter(true, window.getSize().x / 2 - 50, window.getSize().y / 10));
			m_objects.push_back(new Counter(false, window.getSize().x / 2 + 50, window.getSize().y / 10));
		}
		
		virtual ~Game(){
			window.setMouseCursorVisible(true);
			eventQueue.removeListener(this);
		}
};

class WinState : public State{
	public:
		WinState(){
			m_objects.push_back(new Label(sf::Vector2f(windowSizeX / 2, windowSizeY * 2 / 10), "Game over", 40));
			m_objects.push_back(new Button([&](){
				machine.removeState();
				machine.addState(new Game);
			}, sf::Vector2f(windowSizeX / 2, windowSizeY * 4 / 10), "Play again"));
			m_objects.push_back(new Button([&](){
				machine.removeState();
				machine.addState(new MainMenu);
			}, sf::Vector2f(windowSizeX / 2, windowSizeY * 5 / 10), "Main Menu"));
			m_objects.push_back(new Button([&](){
				window.close();
			}, sf::Vector2f(windowSizeX / 2, windowSizeY * 6 / 10), "Exit"));
		}
};

class Pause : public State{
	public:
		void input(const sf::Event& event) override{
			State::input(event);
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				machine.removeState();
		}
		
		Pause(){
			window.setMouseCursorVisible(true);
			m_objects.push_back(new Label(sf::Vector2f(windowSizeX / 2, windowSizeY * 2 / 10), "Game paused", 40));
			m_objects.push_back(new Button([&](){
				machine.removeState();
			}, sf::Vector2f(windowSizeX / 2, windowSizeY * 4 / 10), "Resume"));
			m_objects.push_back(new Button([&](){
				machine.removeState(2);
				machine.addState(new MainMenu);
			}, sf::Vector2f(windowSizeX / 2, windowSizeY * 5 / 10), "Main Menu"));
			m_objects.push_back(new Button([&](){
				window.close();
			}, sf::Vector2f(windowSizeX / 2, windowSizeY * 6 / 10), "Exit"));
		}
		
		virtual ~Pause(){
			window.setMouseCursorVisible(false);
		}
};

void MainMenu::input(const sf::Event& event){
	State::input(event);
}

MainMenu::MainMenu(){
	m_objects.push_back(new Label(sf::Vector2f(windowSizeX / 2, windowSizeY * 2 / 10), "PONG", 70));
	m_objects.push_back(new Button([&](){
		machine.removeState();
		machine.addState(new Game);
	}, sf::Vector2f(windowSizeX / 2, windowSizeY * 9 / 20), "Play"));
	m_objects.push_back(new Button([&](){
		window.close();
	}, sf::Vector2f(windowSizeX / 2, windowSizeY * 11 / 20), "Exit"));
}

void Game::input(const sf::Event& event){
	State::input(event);
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		machine.addState(new Pause);
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
	eventQueue.handleEvents();
}

void Game::onNotify(const Event& event){
	if(event.type == Event::BallOutOfScreen){
		for(auto o : m_objects)
			o->restart();
	}
	if(event.type == Event::GameOver){
		machine.removeState();
		machine.addState(new WinState);
	}
}

int main(){
	srand(time(NULL));
	
	font.loadFromFile("../assets/fonts/Pixeled.ttf");
	clickSound.loadFromFile("../assets/sounds/ClickSound.wav");
	unclickSound.loadFromFile("../assets/sounds/UnclickSound.wav");
	hoverSound.loadFromFile("../assets/sounds/LeaveSound.wav");
	bounceSound.loadFromFile("../assets/sounds/BonusCube.ogg");
	
	window.create(sf::VideoMode(500, 500), "pong", sf::Style::Fullscreen);
	windowSizeX = window.getSize().x;
	windowSizeY = window.getSize().y;
	
	machine.addState(new MainMenu);
	State* state;
	
	window.setFramerateLimit(60);
	
	sf::Event event;
	
	sf::Clock clock;
	sf::Time time;
	while(window.isOpen()){
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
	machine.destroy();
}