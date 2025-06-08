#pragma once
#include <string>

struct MapData
{
private:
	std::string tilesheet = "";
	std::string name = "";

	int mapWidth = 0;
	int mapHeight = 0;

	int tileWidth = 0;
	int tileHeight = 0;

	int scaleX = 0;
	int scaleY = 0;

	int dataLength = 0;
	int* data = nullptr;

public:
	MapData(const std::string& tilesheet,
		const std::string& name,
		int mapWidth,
		int mapHeight,
		int	tileWidth,
		int tileHeight,
		int scaleX,
		int scaleY,
		int dataLength,
		int* data)
	{
		this->tilesheet = tilesheet;
		this->name = name;

		this->mapWidth = mapWidth;
		this->mapHeight = mapHeight;

		this->tileWidth = tileWidth;
		this->tileHeight = tileHeight;

		this->scaleX = scaleX;
		this->scaleY = scaleY;

		this->dataLength = dataLength;
		this->data = data;
	}

	inline const std::string getTilesheet() { return tilesheet; }
	inline const std::string getName() { return name; }
	inline const int getMapWidth() { return mapWidth; }
	inline const int getMapHeight() { return mapHeight; }
	inline const int getTileWidth() { return tileWidth; }
	inline const int getTileHeight() { return tileHeight; }
	inline const int getScaleX() { return scaleX; }
	inline const int getScaleY() { return scaleY; }
	inline const int getDataLength() { return dataLength; }
	inline const int* getData() { return data; }
};

