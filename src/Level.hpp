#pragma once
#include "GameObject.hpp"
#include "MovableObject.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Wall.hpp"
#include "Mario.hpp"
#include "Monster.hpp"
#include "Coin.hpp"
#include "Flag.hpp"

class Level
{
std::string                 filename;
int                         height = 0;
std::vector<Wall>           walls;
std::vector<Monster>        monsters;
std::vector<Coin>           coins;
std::vector<MoveableObject> mov_objs;
Mario                       mario;
Flag                        flag;

public:
    Level(std::string filename);
};