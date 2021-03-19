//
// Created by Kacper on 12/03/2021.
//

#include "assetManager.hpp"

void AssetManager::load(){
	image.loadFromFile("../assets/textures/spritemap.png");
	sizex = 24;
	sizey = 24;
	
	smallCircle.loadFromImage(image, 
			sf::IntRect(sizex * 8, 0, sizex / 2, sizey / 2));
	mediumCircle.loadFromImage(image, 
			sf::IntRect(sizex * 9, 0, sizex / 2, sizey / 2));
	bigCircle.loadFromImage(image, 
			sf::IntRect(sizex * 10, 0, sizex / 2, sizey / 2));
	
	cherry.loadFromImage(image, 
			sf::IntRect(sizex * 0, sizey * 5, sizex, sizey));
	strawberry.loadFromImage(image,
			sf::IntRect(sizex * 1, sizey * 5, sizex, sizey));
	orange.loadFromImage(image, 
			sf::IntRect(sizex * 2, sizey * 5, sizex, sizey));
	bell.loadFromImage(image, 
			sf::IntRect(sizex * 3, sizey * 5, sizex, sizey));
	apple.loadFromImage(image, 
			sf::IntRect(sizex * 4, sizey * 5, sizex, sizey));
	grapes.loadFromImage(image, 
			sf::IntRect(sizex * 5, sizey * 5, sizex, sizey));
	
	redGhost.right.addFrame(image, sf::IntRect(sizex * 0, sizey * 6, sizex, sizey));
	redGhost.right.addFrame(image, sf::IntRect(sizex * 1, sizey * 6, sizex, sizey));
	redGhost.down.addFrame(image, sf::IntRect(sizex * 2, sizey * 6, sizex, sizey));
	redGhost.down.addFrame(image, sf::IntRect(sizex * 3, sizey * 6, sizex, sizey));
	redGhost.left.addFrame(image, sf::IntRect(sizex * 4, sizey * 6, sizex, sizey));
	redGhost.left.addFrame(image, sf::IntRect(sizex * 5, sizey * 6, sizex, sizey));
	redGhost.up.addFrame(image, sf::IntRect(sizex * 6, sizey * 6, sizex, sizey));
	redGhost.up.addFrame(image, sf::IntRect(sizex * 7, sizey * 6, sizex, sizey));
	redGhost.death.addFrame(image, sf::IntRect(sizex * 6, sizey * 4, sizex, sizey));
	redGhost.death.addFrame(image, sf::IntRect(sizex * 7, sizey * 4, sizex, sizey));
	redGhost.death.addFrame(image, sf::IntRect(sizex * 8, sizey * 4, sizex, sizey));
	redGhost.death.addFrame(image, sf::IntRect(sizex * 9, sizey * 4, sizex, sizey));
	
	orangeGhost.right.addFrame(image, sf::IntRect(sizex * 0, sizey * 9, sizex, sizey));
	orangeGhost.right.addFrame(image, sf::IntRect(sizex * 1, sizey * 9, sizex, sizey));
	orangeGhost.down.addFrame(image, sf::IntRect(sizex * 2, sizey * 9, sizex, sizey));
	orangeGhost.down.addFrame(image, sf::IntRect(sizex * 3, sizey * 9, sizex, sizey));
	orangeGhost.left.addFrame(image, sf::IntRect(sizex * 4, sizey * 9, sizex, sizey));
	orangeGhost.left.addFrame(image, sf::IntRect(sizex * 5, sizey * 9, sizex, sizey));
	orangeGhost.up.addFrame(image, sf::IntRect(sizex * 6, sizey * 9, sizex, sizey));
	orangeGhost.up.addFrame(image, sf::IntRect(sizex * 7, sizey * 9, sizex, sizey));
	orangeGhost.death.addFrame(image, sf::IntRect(sizex * 6, sizey * 4, sizex, sizey));
	orangeGhost.death.addFrame(image, sf::IntRect(sizex * 7, sizey * 4, sizex, sizey));
	orangeGhost.death.addFrame(image, sf::IntRect(sizex * 8, sizey * 4, sizex, sizey));
	orangeGhost.death.addFrame(image, sf::IntRect(sizex * 9, sizey * 4, sizex, sizey));
	
	pinkGhost.right.addFrame(image, sf::IntRect(sizex * 0, sizey * 8, sizex, sizey));
	pinkGhost.right.addFrame(image, sf::IntRect(sizex * 1, sizey * 8, sizex, sizey));
	pinkGhost.down.addFrame(image, sf::IntRect(sizex * 2, sizey * 8, sizex, sizey));
	pinkGhost.down.addFrame(image, sf::IntRect(sizex * 3, sizey * 8, sizex, sizey));
	pinkGhost.left.addFrame(image, sf::IntRect(sizex * 4, sizey * 8, sizex, sizey));
	pinkGhost.left.addFrame(image, sf::IntRect(sizex * 5, sizey * 8, sizex, sizey));
	pinkGhost.up.addFrame(image, sf::IntRect(sizex * 6, sizey * 8, sizex, sizey));
	pinkGhost.up.addFrame(image, sf::IntRect(sizex * 7, sizey * 8, sizex, sizey));
	pinkGhost.death.addFrame(image, sf::IntRect(sizex * 6, sizey * 4, sizex, sizey));
	pinkGhost.death.addFrame(image, sf::IntRect(sizex * 7, sizey * 4, sizex, sizey));
	pinkGhost.death.addFrame(image, sf::IntRect(sizex * 8, sizey * 4, sizex, sizey));
	pinkGhost.death.addFrame(image, sf::IntRect(sizex * 9, sizey * 4, sizex, sizey));
	
	blueGhost.right.addFrame(image, sf::IntRect(sizex * 8, sizey * 8, sizex, sizey));
	blueGhost.right.addFrame(image, sf::IntRect(sizex * 9, sizey * 8, sizex, sizey));
	blueGhost.down.addFrame(image, sf::IntRect(sizex * 10, sizey * 8, sizex, sizey));
	blueGhost.down.addFrame(image, sf::IntRect(sizex * 11, sizey * 8, sizex, sizey));
	blueGhost.left.addFrame(image, sf::IntRect(sizex * 12, sizey * 8, sizex, sizey));
	blueGhost.left.addFrame(image, sf::IntRect(sizex * 13, sizey * 8, sizex, sizey));
	blueGhost.up.addFrame(image, sf::IntRect(sizex * 14, sizey * 8, sizex, sizey));
	blueGhost.up.addFrame(image, sf::IntRect(sizex * 15, sizey * 8, sizex, sizey));
	blueGhost.death.addFrame(image, sf::IntRect(sizex * 6, sizey * 4, sizex, sizey));
	blueGhost.death.addFrame(image, sf::IntRect(sizex * 7, sizey * 4, sizex, sizey));
	blueGhost.death.addFrame(image, sf::IntRect(sizex * 8, sizey * 4, sizex, sizey));
	blueGhost.death.addFrame(image, sf::IntRect(sizex * 9, sizey * 4, sizex, sizey));
	
	deadGhost.right.addFrame(image, sf::IntRect(sizex * 8, sizey * 6, sizex, sizey));
	deadGhost.right.addFrame(image, sf::IntRect(sizex * 9, sizey * 6, sizex, sizey));
	deadGhost.down.addFrame(image, sf::IntRect(sizex * 10, sizey * 6, sizex, sizey));
	deadGhost.down.addFrame(image, sf::IntRect(sizex * 11, sizey * 6, sizex, sizey));
	deadGhost.left.addFrame(image, sf::IntRect(sizex * 12, sizey * 6, sizex, sizey));
	deadGhost.left.addFrame(image, sf::IntRect(sizex * 13, sizey * 6, sizex, sizey));
	deadGhost.up.addFrame(image, sf::IntRect(sizex * 14, sizey * 6, sizex, sizey));
	deadGhost.up.addFrame(image, sf::IntRect(sizex * 15, sizey * 6, sizex, sizey));
	
	pacman.left.addFrame(image, sf::IntRect(sizex * 0, sizey * 3, sizex, sizey));
	pacman.left.addFrame(image, sf::IntRect(sizex * 2, sizey * 3, sizex, sizey));
	pacman.down.addFrame(image, sf::IntRect(sizex * 5, sizey * 3, sizex, sizey));
	pacman.down.addFrame(image, sf::IntRect(sizex * 7, sizey * 3, sizex, sizey));
	pacman.right.addFrame(image, sf::IntRect(sizex * 4, sizey * 3, sizex, sizey));
	pacman.right.addFrame(image, sf::IntRect(sizex * 6, sizey * 3, sizex, sizey));
	pacman.up.addFrame(image, sf::IntRect(sizex * 1, sizey * 3, sizex, sizey));
	pacman.up.addFrame(image, sf::IntRect(sizex * 3, sizey * 3, sizex, sizey));
	pacman.death.addFrame(image, sf::IntRect(sizex * 4, sizey * 7, sizex, sizey));
	pacman.death.addFrame(image, sf::IntRect(sizex * 5, sizey * 7, sizex, sizey));
	pacman.death.addFrame(image, sf::IntRect(sizex * 6, sizey * 7, sizex, sizey));
	pacman.death.addFrame(image, sf::IntRect(sizex * 7, sizey * 7, sizex, sizey));
	pacman.death.addFrame(image, sf::IntRect(sizex * 8, sizey * 7, sizex, sizey));
	pacman.death.addFrame(image, sf::IntRect(sizex * 9, sizey * 7, sizex, sizey));
	pacman.death.addFrame(image, sf::IntRect(sizex * 10, sizey * 7, sizex, sizey));
	pacman.death.addFrame(image, sf::IntRect(sizex * 11, sizey * 7, sizex, sizey));
	pacman.death.addFrame(image, sf::IntRect(sizex * 12, sizey * 7, sizex, sizey));
	pacman.death.addFrame(image, sf::IntRect(sizex * 13, sizey * 7, sizex, sizey));
	pacman.death.addFrame(image, sf::IntRect(sizex * 14, sizey * 7, sizex, sizey));
	pacman.death.addFrame(image, sf::IntRect(sizex * 15, sizey * 7, sizex, sizey));
}
