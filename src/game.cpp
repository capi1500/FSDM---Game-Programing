//
// Created by Kacper on 12/03/2021.
//

#include "game.hpp"
#include <systems/inputHandler.hpp>
#include <entities/smallPoint.hpp>
#include <systems/assetManager.hpp>
#include <entities/fruit.hpp>
#include <entities/pacman.hpp>

Signal<GameEvent> gameEventSignal;

Scene* Game::getScene(){
	return static_cast<Scene*>(scenes.get());
}

Game::Game(){
	AssetManager::get().load();
	
	window.create(sf::VideoMode(500, 500), "Pacman");
	InputHandler::get().registerWindow(&window);
	active = true;
	gameEventSignal.addListener(this);
	
	Scene* scene = new Scene(scenes);
	scene->addEntity(new SmallPoint);
	/*scene->addEntity(new Fruit(Fruit::Cherry));
	scene->addEntity(new Fruit(Fruit::Strawberry));
	scene->addEntity(new Fruit(Fruit::Orange));
	scene->addEntity(new Fruit(Fruit::Bell));
	scene->addEntity(new Fruit(Fruit::Apple));
	scene->addEntity(new Fruit(Fruit::Grapes));*/
	scene->addEntity(new Pacman());
	
	scenes.add(scene);
}

Game::~Game(){
	gameEventSignal.removeListener(this);
	scenes.clear();
}

void Game::run(){
	Scene* scene;
	sf::Time time;
	sf::Clock clock;
	while(active){
		time = clock.restart();
		
		scene = getScene();
		
		InputHandler::get().handleEvents();
		gameEventSignal.handleEvents();
		
		scene->update(time);
		
		window.clear();
		window.draw(*scene);
		window.display();
	}
	window.close();
}

void Game::onNotify(const GameEvent& event){
	if(event.type == GameEvent::Closed)
		active = false;
}
