//
// Created by Kacper on 12/03/2021.
//

#include "assetManager.hpp"

void AssetManager::load(){
	image.loadFromFile("../assets/textures/spritemap.png");
	texture.loadFromImage(image);
	sizex = 24;
	sizey = 24;
	
	// colectibles
	
	smallCircle.setTexture(texture);
	smallCircle.setTextureRect(sf::IntRect(sizex * 8, 0, sizex / 2, sizey / 2));
	bigCircle.setTexture(texture);
	bigCircle.setTextureRect(sf::IntRect(sizex * 10, 0, sizex / 2, sizey / 2));
	
	cherry.setTexture(texture);
	cherry.setTextureRect(sf::IntRect(sizex * 0, sizey * 5, sizex, sizey));
	strawberry.setTexture(texture);
	strawberry.setTextureRect(sf::IntRect(sizex * 1, sizey * 5, sizex, sizey));
	orange.setTexture(texture);
	orange.setTextureRect(sf::IntRect(sizex * 2, sizey * 5, sizex, sizey));
	bell.setTexture(texture);
	bell.setTextureRect(sf::IntRect(sizex * 3, sizey * 5, sizex, sizey));
	apple.setTexture(texture);
	apple.setTextureRect(sf::IntRect(sizex * 4, sizey * 5, sizex, sizey));
	grapes.setTexture(texture);
	grapes.setTextureRect(sf::IntRect(sizex * 5, sizey * 5, sizex, sizey));
	
	// map
	
	doubleLeftUp.setTexture(texture);
	doubleLeftDown.setTexture(texture);
	doubleRightUp.setTexture(texture);
	doubleRightDown.setTexture(texture);
	doubleVerticalLeft.setTexture(texture);
	doubleVerticalRight.setTexture(texture);
	doubleHorizontalUpper.setTexture(texture);
	doubleHorizontalLower.setTexture(texture);
	doubleSpecialUp1.setTexture(texture);
	doubleSpecialUp2.setTexture(texture);
	doubleSpecialLeft1.setTexture(texture);
	doubleSpecialLeft2.setTexture(texture);
	doubleSpecialRight1.setTexture(texture);
	doubleSpecialRight2.setTexture(texture);
	
	singleLeftUp.setTexture(texture);
	singleLeftDown.setTexture(texture);
	singleRightUp.setTexture(texture);
	singleRightDown.setTexture(texture);
	singleVerticalLeft.setTexture(texture);
	singleVerticalRight.setTexture(texture);
	singleHorizontalUpper.setTexture(texture);
	singleHorizontalLower.setTexture(texture);
	
	door.setTexture(texture);
	rectLeftUp.setTexture(texture);
	rectLeftDown.setTexture(texture);
	rectRightUp.setTexture(texture);
	rectRightDown.setTexture(texture);
	
	empty.setTexture(texture);
	
	doubleLeftUp.setTextureRect(sf::IntRect(sizex * 17 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	doubleLeftDown.setTextureRect(sf::IntRect(sizex * 21 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	doubleRightUp.setTextureRect(sf::IntRect(sizex * 16 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	doubleRightDown.setTextureRect(sf::IntRect(sizex * 20 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	doubleVerticalLeft.setTextureRect(sf::IntRect(sizex * 18 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	doubleVerticalRight.setTextureRect(sf::IntRect(sizex * 17 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	doubleHorizontalUpper.setTextureRect(sf::IntRect(sizex * 26 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	doubleHorizontalLower.setTextureRect(sf::IntRect(sizex * 28 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	doubleSpecialUp1.setTextureRect(sf::IntRect(sizex * 27 / 2, sizey * 5 / 2, sizex / 2, sizey / 2));
	doubleSpecialUp2.setTextureRect(sf::IntRect(sizex * 26 / 2, sizey * 5 / 2, sizex / 2, sizey / 2));
	doubleSpecialLeft1.setTextureRect(sf::IntRect(sizex * 23 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	doubleSpecialLeft2.setTextureRect(sf::IntRect(sizex * 25 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	doubleSpecialRight1.setTextureRect(sf::IntRect(sizex * 22 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	doubleSpecialRight2.setTextureRect(sf::IntRect(sizex * 24 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	
	singleLeftUp.setTextureRect(sf::IntRect(sizex * 18 / 2, sizey * 5 / 2, sizex / 2, sizey / 2));
	singleLeftDown.setTextureRect(sf::IntRect(sizex * 20 / 2, sizey * 5 / 2, sizex / 2, sizey / 2));
	singleRightUp.setTextureRect(sf::IntRect(sizex * 19 / 2, sizey * 5 / 2, sizex / 2, sizey / 2));
	singleRightDown.setTextureRect(sf::IntRect(sizex * 21 / 2, sizey * 5 / 2, sizex / 2, sizey / 2));
	singleVerticalLeft.setTextureRect(sf::IntRect(sizex * 24 / 2, sizey * 3 / 2, sizex / 2, sizey / 2));
	singleVerticalRight.setTextureRect(sf::IntRect(sizex * 23 / 2, sizey * 3 / 2, sizex / 2, sizey / 2));
	singleHorizontalUpper.setTextureRect(sf::IntRect(sizex * 20 / 2, sizey * 3 / 2, sizex / 2, sizey / 2));
	singleHorizontalLeft.setTextureRect(sf::IntRect(sizex * 29 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	
	door.setTextureRect(sf::IntRect(sizex * 31 / 2, sizey * 4 / 2, sizex / 2, sizey / 2));
	rectLeftUp.setTextureRect(sf::IntRect(sizex * 29 / 2, sizey * 3 / 2, sizex / 2, sizey / 2));
	rectLeftDown.setTextureRect(sf::IntRect(sizex * 31 / 2, sizey * 3 / 2, sizex / 2, sizey / 2));
	rectRightUp.setTextureRect(sf::IntRect(sizex * 28 / 2, sizey * 3 / 2, sizex / 2, sizey / 2));
	rectRightDown.setTextureRect(sf::IntRect(sizex * 30 / 2, sizey * 3 / 2, sizex / 2, sizey / 2));
	
	empty.setTextureRect(sf::IntRect(sizex * 11, 0, sizex / 2, sizey / 2));
	
	// entities
	
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
