//
// Created by Kacper on 19/03/2021.
//

#ifndef PROGRAMOWANIEGIER_ANIMATION_HPP
#define PROGRAMOWANIEGIER_ANIMATION_HPP

#include <SFML/Graphics/Texture.hpp>

class Animation{
	private:
		std::vector<sf::Texture*> frames;
	public:
		const sf::Texture& getFrame(size_t i);
		void addFrame(const sf::Image& image, const sf::IntRect& frame);
		size_t frameCount() const;
		
		~Animation();
};

#endif //PROGRAMOWANIEGIER_ANIMATION_HPP
