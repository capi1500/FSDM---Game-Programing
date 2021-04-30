//
// Created by Kacper on 26/03/2021.
//

#include "map.hpp"
#include <systems/assetManager.hpp>
#include <fstream>
#include <iostream>
#include <stack>

Map::Map(){
	std::ifstream file("../assets/map2.txt");
	char c;
	for(int y = 0; y < 31; y++){
		fields.push_back(std::vector<Field>());
		{
			Field::Type type = Field::Wall;
			if(y == 14)
				type = Field::Empty;
			fields.back().push_back(Field(type, AssetManager::get().empty));
			fields.back().push_back(Field(type, AssetManager::get().empty));
			fields.back().push_back(Field(type, AssetManager::get().empty));
		}
		for(int x = 0; x < 28; x++){
			file.get(c);
			Field::Type type;
			sf::Sprite* sprite;
			switch (c){
				case 'T':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleHorizontalUpper;
					break;
				case 'B':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleHorizontalLower;
					break;
				case 'L':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleVerticalLeft;
					break;
				case 'R':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleVerticalRight;
					break;

				case 'X':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleLeftUpBig;
					break;
				case 'Y':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleRightUpBig;
					break;
				case 'Z':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleLeftDownBig;
					break;
				case 'W':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleRightDownBig;
					break;

				case 't':
					type = Field::Wall;
					sprite = &AssetManager::get().singleHorizontalUpper;
					break;
				case 'b':
					type = Field::Wall;
					sprite = &AssetManager::get().singleHorizontalLower;
					break;
				case 'l':
					type = Field::Wall;
					sprite = &AssetManager::get().singleVerticalLeft;
					break;
				case 'r':
					type = Field::Wall;
					sprite = &AssetManager::get().singleVerticalRight;
					break;

				case 'x':
					type = Field::Wall;
					sprite = &AssetManager::get().singleLeftUp;
					break;
				case 'y':
					type = Field::Wall;
					sprite = &AssetManager::get().singleRightUp;
					break;
				case 'z':
					type = Field::Wall;
					sprite = &AssetManager::get().singleLeftDown;
					break;
				case 'w':
					type = Field::Wall;
					sprite = &AssetManager::get().singleRightDown;
					break;

				case 'q':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleSpecialUp1;
					break;
				case 'Q':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleSpecialUp2;
					break;
				case 'u':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleSpecialRight1;
					break;
				case 'U':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleSpecialLeft1;
					break;
				case 'v':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleSpecialRight2;
					break;
				case 'V':
					type = Field::Wall;
					sprite = &AssetManager::get().doubleSpecialLeft2;
					break;

				case 'e':
					type = Field::Wall;
					sprite = &AssetManager::get().rectLeftUp;
					break;
				case 'E':
					type = Field::Wall;
					sprite = &AssetManager::get().rectRightUp;
					break;
				case 'k':
					type = Field::Wall;
					sprite = &AssetManager::get().rectLeftDown;
					break;
				case 'K':
					type = Field::Wall;
					sprite = &AssetManager::get().rectRightDown;
					break;
				case ']':
					type = Field::Wall;
					sprite = &AssetManager::get().rectLeftEnd;
					break;
				case '[':
					type = Field::Wall;
					sprite = &AssetManager::get().rectRightEnd;
					break;
				case 'd':
					type = Field::Door;
					sprite = &AssetManager::get().door;
					break;

				case 'f':
					type = Field::Wall;
					sprite = &AssetManager::get().singleSpecialRightUp;
					break;
				case 'F':
					type = Field::Wall;
					sprite = &AssetManager::get().singleSpecialLeftUp;
					break;
				case 'j':
					type = Field::Wall;
					sprite = &AssetManager::get().singleSpecialLeftDown;
					break;
				case 'J':
					type = Field::Wall;
					sprite = &AssetManager::get().singleSpecialRightDown;
					break;

				case '.':
					type = Field::Point;
					sprite = &AssetManager::get().smallCircle;
					break;
				case '0':
					type = Field::BigPoint;
					sprite = &AssetManager::get().bigCircle;
					break;
				case 'C':
					type = Field::Cherry;
					sprite = &AssetManager::get().cherry;
				case 'S':
					type = Field::Strawberry;
					sprite = &AssetManager::get().strawberry;
					break;
				case 'O':
					type = Field::Orange;
					sprite = &AssetManager::get().orange;
					break;
				case 'H':
					type = Field::Bell;
					sprite = &AssetManager::get().bell;
					break;
				case 'A':
					type = Field::Apple;
					sprite = &AssetManager::get().apple;
					break;
				case 'G':
					type = Field::Grapes;
					sprite = &AssetManager::get().grapes;
					break;
				default:
					type = Field::Empty;
					sprite = &AssetManager::get().empty;
					break;
			}
			fields.back().push_back(Field(type, *sprite));
		}
		{
			Field::Type type = Field::Wall;
			if(y == 14)
				type = Field::Empty;
			fields.back().push_back(Field(type, AssetManager::get().empty));
			fields.back().push_back(Field(type, AssetManager::get().empty));
		}
		file.get(c);
	}
	
	gameEventSignal.addListener(this);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	for(auto& vec : fields){
		for(auto& e : vec){
			target.draw(e, states);
			states.transform.translate(12, 0);
		}
		states.transform.translate(-12 * 33, 12);
	}
}

Field& Map::getField(const sf::Vector2u& pos){
	return fields[pos.x][pos.y];
}

Field& Map::getField(const unsigned int x, const unsigned int y){
	return fields[x][y];
}

const Field& Map::getField(const sf::Vector2u& pos) const{
	return fields[pos.x][pos.y];
}

const Field& Map::getField(const unsigned int x, const unsigned int y) const{
	return fields[x][y];
}

void Map::onNotify(const GameEvent& event){
	if(event.type == GameEvent::PacmanMove){
		Field& f = getField(event.pacmanMove.position);
		if(f.getType() == Field::Point)
			f.setType(Field::Empty, AssetManager::get().empty);
		else if(f.getType() == Field::BigPoint){
			GameEvent event1;
			event1.type = GameEvent::BigPointEaten;
			gameEventSignal.notify(event1);
			f.setType(Field::Empty, AssetManager::get().empty);
		}
	}
}

std::vector<sf::Vector2u> Map::findShortestPath(const sf::Vector2u& v, const sf::Vector2u& u) const{
	std::cout << "bfs: " << v.x << " " << v.y << " -> " << u.x << " " << u.y << "\n";
	
	std::vector<std::vector<unsigned>> distance(fields.size(), std::vector<unsigned>(fields[0].size(), 4000000000));
	std::vector<std::vector<sf::Vector2u>> parent(fields.size(), std::vector<sf::Vector2u>(fields[0].size()));
	
	std::queue<sf::Vector2u> toVisit;
	
	distance[v.x][v.y] = 0;
	toVisit.push(v);
	
	int p[4] = {0, 1, 2, 3};
	std::random_shuffle(p, p + 4);
	
	while(!toVisit.empty()){
		sf::Vector2u a = toVisit.front();
		toVisit.pop();
		
		//std::cout << "\t" << a.x << " " << a.y << " " << distance[a.x][a.y] << "\n";
		
		if(a == u){
			std::vector<sf::Vector2u> out;
			out.push_back(u);
			while(a != v){
				a = parent[a.x][a.y];
				out.push_back(a);
			}
			std::reverse(out.begin(), out.end());
			return out;
		}
		
		for(int d = 0; d < 4; d++){
			sf::Vector2u next = sf::Vector2u((a.x + dx[p[d]] + fields.size()) % fields.size(), (a.y + dy[p[d]] + fields[0].size()) % fields[0].size());
			//std::cout << "\t\t" << next.x << " " << next.y << "\n";
			if(getField(next).isCanPass()){
				unsigned dist = distance[a.x][a.y] + 1;
				if(dist < distance[next.x][next.y]){
					distance[next.x][next.y] = dist;
					parent[next.x][next.y] = a;
					toVisit.push(next);
				}
			}
		}
	}
	
	return std::vector<sf::Vector2u>();
}
