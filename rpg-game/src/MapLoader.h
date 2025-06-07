#pragma once
#include <iostream>
#include "MapData.h"

class MapLoader
{
public:
	void saveNew(std::string filename);

	// Pass a map by reference
	void load(std::string filename, MapData& data);
};

