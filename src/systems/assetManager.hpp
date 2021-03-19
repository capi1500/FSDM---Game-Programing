//
// Created by Kacper on 12/03/2021.
//

#ifndef PROGRAMOWANIEGIER_ASSETMANAGER_HPP
#define PROGRAMOWANIEGIER_ASSETMANAGER_HPP

#include <misc/singleton.hpp>
#include <SFML/Graphics/Font.hpp>
#include <misc/animation.hpp>

class AssetManager : public Singleton<AssetManager>{
	private:
		sf::Image image;
		unsigned sizex;
		unsigned sizey;
	public:
		sf::Font font;
		
		sf::Texture smallCircle;
		sf::Texture mediumCircle;
		sf::Texture bigCircle;
		
		sf::Texture cherry;
		sf::Texture strawberry;
		sf::Texture orange;
		sf::Texture bell;
		sf::Texture apple;
		sf::Texture grapes;
		
		struct EntityAssetPack{
			Animation up;
			Animation down;
			Animation left;
			Animation right;
			Animation death;
		};
		
		EntityAssetPack redGhost;
		EntityAssetPack pinkGhost;
		EntityAssetPack orangeGhost;
		EntityAssetPack blueGhost;
		EntityAssetPack deadGhost;
		EntityAssetPack pacman;
		
		void load();
};

#endif //PROGRAMOWANIEGIER_ASSETMANAGER_HPP
