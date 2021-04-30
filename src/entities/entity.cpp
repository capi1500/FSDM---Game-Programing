//
// Created by Kacper on 12/03/2021.
//

#include "entity.hpp"

Entity::Entity(){
	visible = active = exists = true;
}

bool Entity::isVisible() const{
	return visible;
}

bool Entity::isActive() const{
	return active;
}

bool Entity::isExists() const{
	return exists;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};