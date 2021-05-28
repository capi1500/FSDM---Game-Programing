//
// Created by Kacper on 12/03/2021.
//

#include "game.hpp"
#include <systems/inputHandler.hpp>
#include <systems/assetManager.hpp>
#include <entities/pacman.hpp>
#include <iostream>
#include <entities/ghost.hpp>
#include <systems/console.hpp>

Scene* Game::getScene(){
	return static_cast<Scene*>(scenes.get());
}

Game::Game(){
	AssetManager::get().load();
	
	window.create(sf::VideoMode(12 * 28, 12 * 40), "Pacman");
	window.setFramerateLimit(60);
	
	InputHandler::get().registerWindow(&window);
	active = true;
	gameEventSignal.addListener(this);
	InputHandler::get().addListener(this);
	
	Scene* scene = new Scene(scenes);
	scene->addEntity(new Pacman(map));
	scene->addEntity(new Ghost(map, {35, 29}));
	
	scenes.add(scene);
	
	view = sf::View(sf::FloatRect(36, -36, 12 * 28, 12 * 40));
	long double width = static_cast<long double>(28 * window.getSize().y) / static_cast<long double>(40 * window.getSize().x);
	view.setViewport(sf::FloatRect((1 - width) / 2, 0, width, 1));
	window.setView(view);
	
	window.setVerticalSyncEnabled(true);
}

Game::~Game(){
	gameEventSignal.removeListener(this);
	scenes.clear();
}

void Game::run(){
	Console console;
	console.listenType(Message::Debug);
	
	Statistics statistics;
	gameEventSignal.addListener(&statistics);
	
	Scene* scene;
	sf::Time time;
	sf::Clock clock;
	while(active){
		time = clock.restart();
		
		scene = getScene();
		
		InputHandler::get().handleEvents();
		
		scene->update(time);
		
		gameEventSignal.handleEvents();
		message.handleEvents();
		
		window.clear();
		window.draw(map);
		window.draw(*scene);
		window.draw(statistics);
		window.display();
	}
	gameEventSignal.removeListener(&statistics);
	
	window.close();
}

void Game::onNotify(const GameEvent& event){
	if(event.type == GameEvent::Closed)
		active = false;
}

void Game::onNotify(const sf::Event& event){
	if(event.type == sf::Event::Resized){
		long double width = static_cast<long double>(28 * event.size.height) / static_cast<long double>(40 * event.size.width);
		view.setViewport(sf::FloatRect((1 - width) / 2, 0, width, 1));
		window.setView(view);
	}
}
