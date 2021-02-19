//
// Created by Kacper on 15/01/2021.
//

#ifndef PROGRAMOWANIEGIER_SOUNDBOARD_HPP
#define PROGRAMOWANIEGIER_SOUNDBOARD_HPP

#include <SFML/Audio/Sound.hpp>
#include <vector>

class SoundBoard{
	private:
		int m_id;
		std::vector<sf::Sound> m_sounds;
	public:
		void play(const sf::SoundBuffer& sound);
		
		SoundBoard();
};

#endif //PROGRAMOWANIEGIER_SOUNDBOARD_HPP
