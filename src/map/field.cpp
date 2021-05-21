//
// Created by Kacper on 26/03/2021.
//

#include "field.hpp"

Field::Field(Field::Type type){
	setType(type);
}


Field::Field(){
	type = Type::Empty;
}

Field::Type Field::getType() const{
	return type;
}

bool Field::isCanPass() const{
	return canPass;
}

void Field::setType(Field::Type type){
	Field::type = type;
	canPass = (type != Door && type != Wall);
}
