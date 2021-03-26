//
// Created by Kacper on 26/03/2021.
//

#include "map.hpp"
#include <systems/assetManager.hpp>

Map::Map(int fields) : fields({{Field(Field::Wall, AssetManager::get().pacman),}}){
}
