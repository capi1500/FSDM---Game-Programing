//
// Created by Kacper on 15/01/2021.
//

#include "soundBoard.hpp"

void SoundBoard::play(const sf::SoundBuffer& sound){
	m_sounds[m_id].setBuffer(sound);
	m_sounds[m_id].play();
	m_id++;
	if(m_id == 50)
		m_id = 0;
}

SoundBoard::SoundBoard(){
	m_sounds.resize(50);
	m_id = 0;
}

SoundBoard::~SoundBoard(){
	for(auto& s : m_sounds){
		s.stop();
	}
	m_sounds.clear();
}
