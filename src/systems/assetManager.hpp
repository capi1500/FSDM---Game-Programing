//
// Created by Kacper on 12/03/2021.
//

#ifndef PROGRAMOWANIEGIER_ASSETMANAGER_HPP
#define PROGRAMOWANIEGIER_ASSETMANAGER_HPP

#include <misc/singleton.hpp>
#include <SFML/Graphics/Font.hpp>
#include <misc/animation.hpp>
#include <SFML/Graphics/Sprite.hpp>

class AssetManager : public Singleton<AssetManager>{
	private:
		sf::Image image;
		sf::Texture texture;
		unsigned sizex;
		unsigned sizey;
	public:
		sf::Font font;
		
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
		
		sf::Sprite doubleLeftUp;
		sf::Sprite doubleLeftDown;
		sf::Sprite doubleRightUp;
		sf::Sprite doubleRightDown;
		sf::Sprite doubleVertical;
		sf::Sprite doubleHorizontal;
		sf::Sprite doubleSpecialUp1;
		sf::Sprite doubleSpecialUp2;
		sf::Sprite doubleSpecialLeft1;
		sf::Sprite doubleSpecialLeft2;
		sf::Sprite doubleSpecialRight1;
		sf::Sprite doubleSpecialRight2;
		
		sf::Sprite singleLeftUp;
		sf::Sprite singleLeftDown;
		sf::Sprite singleRightUp;
		sf::Sprite singleRightDown;
		sf::Sprite singleVertical;
		sf::Sprite singleHorizontal;
		
		sf::Sprite door;
		sf::Sprite rectLeftUp;
		sf::Sprite rectLeftDown;
		sf::Sprite rectRightUp;
		sf::Sprite rectRightDown;
		
		sf::Sprite empty;
		
		sf::Sprite smallCircle;
		sf::Sprite bigCircle;
		
		sf::Sprite cherry;
		sf::Sprite strawberry;
		sf::Sprite orange;
		sf::Sprite bell;
		sf::Sprite apple;
		sf::Sprite grapes;
		
		void load();
};

#endif //PROGRAMOWANIEGIER_ASSETMANAGER_HPP
