//
// Created by Kacper on 12/03/2021.
//

#include <game.hpp>
#include "scene.hpp"
#include "inputHandler.hpp"

void Scene::refresh(){
	for(unsigned i = 0; i < entities.size(); i++){
		if(!entities[i]->isExists()){
			std::swap(entities[i], entities.back());
			delete entities.back();
			entities.pop_back();
		}
	}
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	for(auto e : entities){
		if(e->isExists() && e->isVisible())
			target.draw(*e, states);
	}
}

void Scene::update(const sf::Time& time){
	for(auto e : entities){
		if(e->isExists() && e->isActive())
			e->update(time);
	}
	refresh();
}

void Scene::addEntity(Entity* entity){
	entities.push_back(entity);
}

Scene::Scene(FiniteStateMachine& fsm) : FiniteState(fsm){
	InputHandler::get().addListener(this);
}

Scene::~Scene(){
	InputHandler::get().removeListener(this);
}

void Scene::onNotify(const sf::Event& event){
	if(isActive()){
		if(event.type == sf::Event::Closed){
			GameEvent gameEvent;
			gameEvent.type = GameEvent::Closed;
			gameEventSignal.notify(gameEvent);
		}
	}
}
