//
// Created by Kacper on 04/12/2020.
//

#ifndef PROGRAMOWANIEGIER_STATE_HPP
#define PROGRAMOWANIEGIER_STATE_HPP

#include <vector>
#include <Objects/object.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

class State{
	private:
		bool m_delete;
	protected:
		std::vector<Object*> m_objects;
	public:
		virtual void draw(sf::RenderWindow& window);
		virtual void update(const sf::Time& time);
		virtual void input(const sf::Event& event);
		
		bool isDelete() const;
		void setDelete(bool _delete);
		
		State();
		virtual ~State();
};

#endif //PROGRAMOWANIEGIER_STATE_HPP
