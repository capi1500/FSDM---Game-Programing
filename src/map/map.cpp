//
// Created by Kacper on 26/03/2021.
//

#include "map.hpp"
#include <systems/assetManager.hpp>
#include <fstream>
#include <iostream>
#include <graphicSettings.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

const size_t sizex = (28 + 5) * 2;
const size_t sizey = 31 * 2;

Map::Map(){
	std::ifstream file("../assets/map2.txt");
	char c;
	fields.resize(sizex, std::vector<Field>(sizey));
	sprites.resize(sizex / 2, std::vector<sf::Sprite*>(sizey / 2));
	
	
	auto produceTile = [this](unsigned x, unsigned y, Field::Type type, sf::Sprite& sprite){
		sprites[x][y] = &sprite;
		
		fields[2 * x + 1][2 * y + 1] = Field(type);
		fields[2 * x][2 * y] = Field(Field::Type::Wall);
		if(fields[2 * x + 1][2 * y + 1].isCanPass()){
			if(x == 0)
				fields[2 * x][2 * y + 1] = Field(Field::Type::Wall);
			else
				fields[2 * x][2 * y + 1] = Field(fields[2 * x - 1][2 * y + 1].isCanPass() ? Field::Type::Empty : Field::Type::Wall);
			
			if(y == 0)
				fields[2 * x + 1][2 * y] = Field(Field::Type::Wall);
			else
				fields[2 * x + 1][2 * y] = Field(fields[2 * x + 1][2 * y - 1].isCanPass() ? Field::Type::Empty : Field::Type::Wall);
			
			if(x != 0 && y != 0 &&
					fields[2 * x + 1][2 * y - 1].isCanPass() &&
					fields[2 * x - 1][2 * y + 1].isCanPass() &&
					fields[2 * x - 1][2 * y - 1].isCanPass())
				fields[2 * x][2 * y] = Field(Field::Type::Empty);
		}
		else{
			fields[2 * x][2 * y + 1] = Field(Field::Type::Wall);
			fields[2 * x + 1][2 * y] = Field(Field::Type::Wall);
		}
	};
	
	
	for(int y = 0; y < 31; y++){
		{
			Field::Type type = Field::Wall;
			if(y == 14)
				type = Field::Empty;
			produceTile(0, y, type, AssetManager::get().empty);
			produceTile(1, y, type, AssetManager::get().empty);
			produceTile(2, y, type, AssetManager::get().empty);
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
					type = Field::Wall;
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
					break;/*
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
					break;*/
				default:
					type = Field::Empty;
					sprite = &AssetManager::get().empty;
					break;
			}
			produceTile(3 + x, y, type, *sprite);
		}
		{
			Field::Type type = Field::Wall;
			if(y == 14)
				type = Field::Empty;
			produceTile(3 + 28 + 0, y, type, AssetManager::get().empty);
			produceTile(3 + 28 + 1, y, type, AssetManager::get().empty);
		}
		file.get(c);
	}
	
	fields[34][24] = Field(Field::Type::Door);
	fields[34][25] = Field(Field::Type::Door);
	fields[34][26] = Field(Field::Type::Door);
	
	gameEventSignal.addListener(this);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	for(auto& vec : sprites){
		for(auto& e : vec){
			target.draw(*e, states);
			states.transform.translate(0, GraphicSettings::fieldSize * 2);
		}
		states.transform.translate(GraphicSettings::fieldSize * 2, -(GraphicSettings::fieldSize * 2) * 31);
	}
	states.transform.translate(-(GraphicSettings::fieldSize * 2) * 33, 0);
	/*
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(GraphicSettings::fieldSize, GraphicSettings::fieldSize));
	rect.setOutlineThickness(1);
	//rect.setFillColor(sf::Color::Transparent);
	int x = 0, y = 0;
	for(auto& vec : fields){
		x = 0;
		for(auto& e : vec){
			if(x % 2 == 1 && y % 2 == 1)
				rect.setOutlineThickness(2);
			else
				rect.setOutlineThickness(1);
			
			rect.setOutlineColor(e.isCanPass() ? sf::Color::Green : sf::Color::Red);
			if(e.getType() == Field::Type::Door)
				rect.setOutlineColor(sf::Color::Blue);
			
			target.draw(rect, states);
			states.transform.translate(0, GraphicSettings::fieldSize);
			x++;
		}
		states.transform.translate(GraphicSettings::fieldSize, -(GraphicSettings::fieldSize) * 62);
		y++;
	}*/
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
		if(f.getType() == Field::Point){
			GameEvent event1;
			event1.type = GameEvent::SmallPointEaten;
			gameEventSignal.notify(event1);
			f.setType(Field::Empty);
			sprites[event.pacmanMove.position.x / 2][event.pacmanMove.position.y / 2] = &AssetManager::get().empty;
		}
		else if(f.getType() == Field::BigPoint){
			GameEvent event1;
			event1.type = GameEvent::BigPointEaten;
			gameEventSignal.notify(event1);
			f.setType(Field::Empty);
			sprites[event.pacmanMove.position.x / 2][event.pacmanMove.position.y / 2] = &AssetManager::get().empty;
		}
	}
}

std::vector<sf::Vector2u> Map::findShortestPath(const sf::Vector2u& v, const sf::Vector2u& u, bool canPassDoor, const sf::Vector2u& blocked) const{
	std::vector<std::vector<unsigned>> distance(sizex, std::vector<unsigned>(sizey, 4000000000));
	std::vector<std::vector<sf::Vector2u>> parent(sizex, std::vector<sf::Vector2u>(sizey));
	
	std::queue<sf::Vector2u> toVisit;
	
	distance[v.x][v.y] = 0;
	toVisit.push(v);
	
	int p[4] = {0, 1, 2, 3};
	std::random_shuffle(p, p + 4);
	
	while(!toVisit.empty()){
		sf::Vector2u a = toVisit.front();
		toVisit.pop();
		
		if(a == u){
			std::vector<sf::Vector2u> out;
			out.push_back(a);
			while(a != v){
				a = parent[a.x][a.y];
				out.push_back(a);
			}
			out.pop_back();
			std::reverse(out.begin(), out.end());
			return out;
		}
		
		for(int d = 0; d < 4; d++){
			sf::Vector2u next = sf::Vector2u((sizex + a.x + dx[p[d]]) % sizex, a.y + dy[p[d]]);
			if(next != blocked && (getField(next).isCanPass() || (canPassDoor && getField(next).getType() == Field::Door))){
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
