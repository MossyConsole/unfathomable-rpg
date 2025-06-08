#include "MapLoader.h"
#include <fstream>
#include <string>
#include <vector>

void MapLoader::saveNew(std::string filename)
{
	std::ofstream file;

	file.open("assets/maps/" + filename);
	file << "write this whole thing" << std::endl;
	file.close();
}

void MapLoader::load(std::string filename, MapData& data)
{
	std::ifstream file("assets/maps/" + filename);
	std::string lineBuffer;

	bool printDebugInfo = true;
	bool readingMap = false;
	bool mapEnds = false;
	bool mapHasEnded = false;
	unsigned short int lines = 0;

	if (file.is_open())
	{
		while (std::getline(file, lineBuffer))
		{
			lines++;

			// Check if map file is valid before reading
			if (!readingMap)
			{
				if (lineBuffer == "|Map|")
				{
					readingMap = true;

					// Read the file again to find |\Map|
					file.close();

					std::ifstream file2("assets/maps/" + filename);
					std::string lineBuffer2;

					if (file2.is_open())
					{
						while (std::getline(file2, lineBuffer2))
						{
							if (lineBuffer2 == "|~Map|")
							{
								mapEnds = true;
								break;
							}
						}

						if (!mapEnds)
						{
							std::cout << "No |~Map| tag found" << std::endl;
							break;
						}
					}
					else
					{
						std::cout << "Unable to open second time, file: " << filename << std::endl;
					}

					lines = 0;
					file2.close();
					file.open("assets/maps/" + filename);

					continue;
				}
				if (!readingMap)
				{
					std::cout << "No |Map| tag found" << std::endl;
					break;
				}
			}

			// Read map file
			if (readingMap && lineBuffer != "|Map|" && lineBuffer != "|~Map|" && !mapHasEnded)
			{
				int endLine;
				if (lineBuffer.find("~") != -1)
					endLine = lineBuffer.find("~");
				else
					continue;

				int equal;
				if (lineBuffer.find("=") != -1)
					equal = lineBuffer.find("=");
				else
				{
					std::cout << "No value assigned to variable at line: " << lineBuffer << " of " << filename << std::endl;
					continue;
				}

				// Variable
				std::string variable = lineBuffer.substr(0, equal);

				equal++; // Get rid of the equality sign 

				// Value
				std::string value = lineBuffer.substr(equal, endLine - equal);

				// Load data
				try
				{
					if (variable == "version")
					{
						data.setVersion(value);
						if (printDebugInfo)
							std::cout << variable << ": " << data.getVersion() << std::endl;
					}
					else if (variable == "tilesheet")
					{
						data.setTilesheet(value);
						if (printDebugInfo)
							std::cout << variable << ": " << data.getTilesheet() << std::endl;
					}
					else if (variable == "name")
					{
						data.setName(value);
						if (printDebugInfo)
							std::cout << variable << ": " << data.getName() << std::endl;
					}
					else if (variable == "tileWidth")
					{
						data.setTileWidth(stoi(value));
						if (printDebugInfo)
							std::cout << variable << ": " << data.getTileWidth() << std::endl;
					}
					else if (variable == "tileHeight")
					{
						data.setTileHeight(stoi(value));
						if (printDebugInfo)
							std::cout << variable << ": " << data.getTileHeight() << std::endl;
					}
					else if (variable == "scaleX")
					{
						data.setScaleX(stoi(value));
						if (printDebugInfo)
							std::cout << variable << ": " << data.getScaleX() << std::endl;
					}
					else if (variable == "scaleY")
					{
						data.setScaleY(stoi(value));
						if (printDebugInfo)
							std::cout << variable << ": " << data.getScaleY() << std::endl;
					}
					else if (variable == "dataLength")
					{
						data.setDataLength(stoi(value));
						if (printDebugInfo)
							std::cout << variable << ": " << data.getDataLength() << std::endl;
					}
					else if (variable == "data")
					{
						int length = data.getDataLength();
						int offset = 0;

						data.setDataPointer(new int[data.getDataLength()]);

						for (int i = 0; i < length; i++)
						{
							int count = value.find(",", offset);
							if (count == -1)
							{
								int end = value.find("~");
								std::string subVal = value.substr(offset, end);
								data.setData(i, stoi(subVal));
								break;
							}
							else
							{
								std::string subVal = value.substr(offset, count - offset);
								data.setData(i, stoi(subVal));
								offset = count + 1;
							}
						}

						if (printDebugInfo)
						{
							for (int i = 0; i < length; i++)
							{
								std::cout << variable << "[" << i << "]" << ": " << data.getData()[i] << std::endl;
							}
						}
					}
				}
				catch (const std::exception&)
				{
					std::cout << "Map could not be parsed at line: " << lines << " of " << filename << ". Map creator error." << std::endl;
				}
			}
			else if (lineBuffer == "|~Map|")
			{
				mapHasEnded = true;
				break;
			}
		}

		file.close();
	}
	else
	{
		std::cout << "Unable to open file: " << filename << std::endl;
	}
}
