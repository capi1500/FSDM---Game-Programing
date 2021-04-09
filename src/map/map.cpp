//
// Created by Kacper on 26/03/2021.
//

#include "map.hpp"
#include <systems/assetManager.hpp>
#include <fstream>
#include <iostream>

Map::Map(){
	std::ifstream file("../assets/map.txt");
	char c;
	for(int y = 0; y < 31; y++){
		fields.push_back(std::vector<Field>());
		for(int x = 0; x < 28; x++){
			file.get(c);
			Field::Type type;
			sf::Sprite* sprite;
			switch(c){
				case 'q':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleLeftUp;
					break;
				case 'e':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleRightUp;
					break;
				case 'z':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleLeftDown;
					break;
				case 'c':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleRightDown;
					break;
				case 'w':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleHorizontal;
					break;
				case 'a':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleVertical;
					break;
				case 't':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleSpecialUp1;
					break;
				case 'r':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleSpecialUp2;
					break;
				case 'f':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleSpecialLeft1;
					break;
				case 'g':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleSpecialLeft2;
					break;
				case 'v':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleSpecialRight1;
					break;
				case 'b':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleSpecialRight2;
					break;
				case '.':
					type = Field::Point;
					sprite = &AssetManager::get().smallCircle;
					break;
				case 'O':
					type = Field::BigPoint;
					sprite = &AssetManager::get().bigCircle;
					break;
				case 'y':
					type = Field::Wall;
					sprite = &AssetManager::get().singleLeftUp;
					break;
				case 'u':
					type = Field::Wall;
					sprite = &AssetManager::get().singleRightUp;
					break;
				case 'h':
					type = Field::Wall;
					sprite = &AssetManager::get().singleLeftDown;
					break;
				case 'j':
					type = Field::Wall;
					sprite = &AssetManager::get().singleRightDown;
					break;
				case '_':
					type = Field::Wall;
					sprite = &AssetManager::get().singleHorizontal;
					break;
				case '|':
					type = Field::Wall;
					sprite = &AssetManager::get().singleVertical;
					break;
				case 'i':
					type = Field::Wall;
					sprite = &AssetManager::get().rectLeftUp;
					break;
				case 'o':
					type = Field::Wall;
					sprite = &AssetManager::get().rectRightUp;
					break;
				case 'k':
					type = Field::Wall;
					sprite = &AssetManager::get().rectLeftDown;
					break;
				case 'l':
					type = Field::Wall;
					sprite = &AssetManager::get().rectRightDown;
					break;
				default:
					type = Field::Empty;
					sprite = &AssetManager::get().empty;
					break;
			}
			fields.back().push_back(Field(type, *sprite));
		}
		file.get(c);
	}
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	for(auto& vec : fields){
		for(auto& e : vec){
			target.draw(e, states);
			states.transform.translate(12, 0);
		}
		states.transform.translate(-12 * 28, 12);
	}
}

Field& Map::getField(const sf::Vector2u& pos){
	return fields[pos.x][pos.y];
}

Field& Map::getField(const unsigned int x, const unsigned int y){
	return fields[x][y];
}
