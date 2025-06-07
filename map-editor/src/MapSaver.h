#pragma once
#include <iostream>
#include <core/MapData.h>

// static keyword makes functions global, and they don't belong to a specific object
class MapSaver
{
public:
	void save(const std::string& filename, const MapData& mapData);
};



