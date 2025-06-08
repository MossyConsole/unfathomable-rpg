#pragma once
#include <string>

struct MapData
{
private:
	std::string version = "";
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

	MapData(){}

	inline const std::string getVersion() { return version; }
	inline const std::string getTilesheet() { return tilesheet; }
	inline const std::string getName() { return name; }
	inline const int getMapWidth() { return mapWidth; }
	inline const int getMapHeight() { return mapHeight; }
	inline const int getTileWidth() { return tileWidth; }
	inline const int getTileHeight() { return tileHeight; }
	inline const int getScaleX() { return scaleX; }
	inline const int getScaleY() { return scaleY; }
	inline const int getDataLength() { return dataLength; }
	inline int* getData() { return data; }

	inline void setVersion(std::string& version) { this->version = version; }
	inline void setTilesheet(std::string& tilesheet) { this->tilesheet = tilesheet; }
	inline void setName(std::string& name) { this->name = name; }
	inline void setMapWidth(int mapWidth) { this->mapWidth = mapWidth; }
	inline void setMapHeight(int mapHeight) { this->mapHeight = mapHeight; }
	inline void setTileWidth(int tileWidth) { this->tileWidth = tileWidth; }
	inline void setTileHeight(int tileHeight) { this->tileHeight = tileHeight; }
	inline void setScaleX(int scaleX) { this->scaleX = scaleX; }
	inline void setScaleY(int scaleY) { this->scaleY = scaleY; }
	inline void setDataLength(int dataLength) { this->dataLength = dataLength; }
	inline void setData(int i, int value) { data[i] = value; }
	inline void setDataPointer(int* data) { this->data = data; }
};

