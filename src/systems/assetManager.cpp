//
// Created by Kacper on 12/03/2021.
//

#include "assetManager.hpp"

void AssetManager::load(){
	image.loadFromFile("../assets/textures/spritemap.png");
	sizex = 24;
	sizey = 24;
	
	smallCircle.loadFromImage(image, sf::IntRect(sizex * 8, 0, sizex / 2, sizey / 2));
}
