#include "MapSaver.h"
#include <fstream>
#include <string>
#include <vector>

#define MAP_VERSION_NUMBER 1

void MapSaver::save(const std::string& filename, MapData& mapData)
{
	std::ofstream file;

	file.open("../rpg-game/assets/maps/" + filename + ".map");


	file << "|Map|" << "\n";

	file << "version=" << MAP_VERSION_NUMBER << "~\n";
	file << "tilesheet=" << mapData.getTilesheet() << "~\n";
	file << "name=" << mapData.getName() << "~\n";

	file << "mapWidth=" << mapData.getMapWidth() << "~\n";
	file << "mapHeight=" << mapData.getMapHeight() << "~\n";

	file << "tileWidth=" << mapData.getTileWidth() << "~\n";
	file << "tileHeight=" << mapData.getTileHeight() << "~\n";

	file << "scaleX=" << mapData.getScaleX() << "~\n";
	file << "scaleY= " << mapData.getScaleY() << "~\n";

	file << "dataLength=" << mapData.getDataLength() << "~\n";

	file << "data=" << "\n\t";
	int width = mapData.getMapWidth();
	int height = mapData.getMapHeight();
	for (size_t y = 0; y <  height - 1; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			file << "\t" << mapData.getData()[y * width + x] << ", ";
		}
		file << "\n";
	}
	for (size_t x = 0; x < width - 1; x++)
	{
		file << mapData.getData()[(height - 1) * width + x] << ", ";
	}
	file << mapData.getData()[mapData.getDataLength()] << "~\n";

	file << "|~Map|" << std::endl;


	file.close();
}