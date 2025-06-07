#include "MapSaver.h"
#include <fstream>
#include <string>
#include <vector>

#define MAP_VERSION_NUMBER 1

void MapSaver::save(const std::string& filename, const MapData& mapData)
{
	std::ofstream file;

	file.open("../rpg-game/assets/maps/" + filename + ".map");


	file << "|Map|" << "\n";

	file << "version=" << MAP_VERSION_NUMBER << "~\n";
	file << "tilesheet=" << mapData.tilesheet << "~\n";
	file << "name=" << mapData.name << "~\n";

	file << "tileWidth=" << mapData.tileWidth << "~\n";
	file << "tileHeight=" << mapData.tileHeight << "~\n";

	file << "scaleX=" << mapData.scaleX << "~\n";
	file << "scaleY= " << mapData.scaleY << "~\n";

	file << "dataLength=" << mapData.dataLength << "~\n";

	/*
	file << "data=" << "~\n";
	int shortLen = mapData.dataLength - 1;
	for (size_t i = 0; i < shortLen; i++)
	{
		file << mapData.data[i] << ", ";
	}
	file << mapData.data[mapData.dataLength] << "~\n";
	*/

	file << "|~Map|" << std::endl;


	file.close();
}