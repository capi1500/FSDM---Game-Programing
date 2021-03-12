//
// Created by Kacper on 12/03/2021.
//

#ifndef PROGRAMOWANIEGIER_SCENE_HPP
#define PROGRAMOWANIEGIER_SCENE_HPP

#include <finiteStateMachine/finiteState.hpp>
#include <vector>
#include <entities/entity.hpp>
#include <signal/listener.hpp>

class Scene : public FiniteState, public sf::Drawable, public Listener<sf::Event>{
	protected:
		std::vector<Entity*> entities;
		
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void refresh();
	public:
		void update(const sf::Time& time);
		
		void addEntity(Entity* entity);
		
		void onNotify(const sf::Event& event) override;
		
		Scene(FiniteStateMachine& fsm);
		~Scene();
};

#endif //PROGRAMOWANIEGIER_SCENE_HPP
