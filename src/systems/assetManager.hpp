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
		EntityAssetPack cyanGhost;
		EntityAssetPack fleeGhost;
		EntityAssetPack deadGhost;
		EntityAssetPack pacman;
		
		sf::Sprite doubleLeftUpBig;
		sf::Sprite doubleLeftDownBig;
		sf::Sprite doubleRightUpBig;
		sf::Sprite doubleRightDownBig;
		sf::Sprite doubleVerticalLeft;
		sf::Sprite doubleVerticalRight;
		sf::Sprite doubleHorizontalUpper;
		sf::Sprite doubleHorizontalLower;
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
		sf::Sprite singleVerticalLeft;
		sf::Sprite singleVerticalRight;
		sf::Sprite singleHorizontalUpper;
		sf::Sprite singleHorizontalLower;
		sf::Sprite singleSpecialLeftUp;
		sf::Sprite singleSpecialRightUp;
		sf::Sprite singleSpecialLeftDown;
		sf::Sprite singleSpecialRightDown;
		
		sf::Sprite door;
		sf::Sprite rectLeftEnd;
		sf::Sprite rectRightEnd;
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
		sf::Sprite apple;
		sf::Sprite melon;
		sf::Sprite boss;
		sf::Sprite bell;
		sf::Sprite key;
		
		sf::Sprite p200;
		sf::Sprite p400;
		sf::Sprite p800;
		sf::Sprite p1600;
		
		void load();
};

#endif //PROGRAMOWANIEGIER_ASSETMANAGER_HPP
