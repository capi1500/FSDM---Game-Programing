//
// Created by Kacper on 19/03/2021.
//

#include "animation.hpp"

const sf::Texture& Animation::getFrame(size_t i){
	return *frames[i];
}

size_t Animation::frameCount() const{
	return frames.size();
}

void Animation::addFrame(const sf::Image& image, const sf::IntRect& frame){
	sf::Texture* t = new sf::Texture;
	t->loadFromImage(image, frame);
	frames.push_back(t);
	
}

Animation::~Animation(){
	for(auto& t : frames){
		delete t;
		t = nullptr;
	}
	frames.clear();
}
