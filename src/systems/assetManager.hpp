//
// Created by Kacper on 12/03/2021.
//

#ifndef PROGRAMOWANIEGIER_ASSETMANAGER_HPP
#define PROGRAMOWANIEGIER_ASSETMANAGER_HPP

#include <misc/singleton.hpp>
#include <SFML/Graphics/Font.hpp>

class AssetManager : public Singleton<AssetManager>{
	private:
		sf::Image image;
		unsigned sizex;
		unsigned sizey;
	public:
		sf::Font font;
		sf::Texture smallCircle;
		
		void load();
};

#endif //PROGRAMOWANIEGIER_ASSETMANAGER_HPP
