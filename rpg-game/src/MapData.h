#pragma once
#include <string>

// Structs are usually used for only data (no variables)
// Public by default, whereas classes are private by default
struct MapData
{
	int version = 0;

	std::string tilesheet = "";
	std::string name = "";

	int tileWidth = 0;
	int tileHeight = 0;

	int scaleX = 0;
	int scaleY = 0;

	int dataLength = 0;
	int* data = nullptr;
};

