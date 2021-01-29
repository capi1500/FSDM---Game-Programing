//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_COUNTER_HPP
#define PROGRAMOWANIEGIER_COUNTER_HPP

#include <Signal/listener.hpp>
#include <SFML/Graphics/Text.hpp>
#include "object.hpp"

class Counter : public Object, public Listener{
	private:
		int m_counter;
		sf::Text m_text;
		bool m_isLeft;
	public:
		void draw(sf::RenderWindow& window) override;
		
		void update(const sf::Time& time) override;
		
		void input(const sf::Event& input) override;
		
		void restart() override;
		
		void onNotify(const Event& event) override;
		
		Counter(bool isLeft, int posx, int posy);
		~Counter();
};

#endif //PROGRAMOWANIEGIER_COUNTER_HPP
