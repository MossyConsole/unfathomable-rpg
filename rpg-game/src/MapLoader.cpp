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

	bool printDebugInfo = false;
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
						data.version = stoi(value);
						if (printDebugInfo)
							std::cout << variable << ": " << data.version << std::endl;
					}
					else if (variable == "tilesheet")
					{
						data.tilesheet = value;
						if (printDebugInfo)
							std::cout << variable << ": " << data.tilesheet << std::endl;
					}
					else if (variable == "name")
					{
						data.name = value;
						if (printDebugInfo)
							std::cout << variable << ": " << data.name << std::endl;
					}
					else if (variable == "tileWidth")
					{
						data.tileWidth = stoi(value);
						if (printDebugInfo)
							std::cout << variable << ": " << data.tileWidth << std::endl;
					}
					else if (variable == "tileHeight")
					{
						data.tileHeight = stoi(value);
						if (printDebugInfo)
							std::cout << variable << ": " << data.tileHeight << std::endl;
					}
					else if (variable == "scaleX")
					{
						data.scaleX = stoi(value);
						if (printDebugInfo)
							std::cout << variable << ": " << data.scaleX << std::endl;
					}
					else if (variable == "scaleY")
					{
						data.scaleY = stoi(value);
						if (printDebugInfo)
							std::cout << variable << ": " << data.scaleY << std::endl;
					}
					else if (variable == "dataLength")
					{
						data.dataLength = stoi(value);
						if (printDebugInfo)
							std::cout << variable << ": " << data.dataLength << std::endl;
					}
					else if (variable == "data")
					{
						int length = data.dataLength;
						int offset = 0;

						// TODO: DELETE THIS LATER
						data.data = new int[length];

						for (int i = 0; i < length; i++)
						{
							int count = value.find(",", offset);
							if (count == -1)
							{
								int end = value.find("~");
								std::string subVal = value.substr(offset, end);
								data.data[i] = stoi(subVal);
								break;
							}
							else
							{
								std::string subVal = value.substr(offset, count - offset);
								data.data[i] = stoi(subVal);
								offset = count + 1;
							}
						}

						if (printDebugInfo)
						{
							for (int i = 0; i < length; i++)
							{
								std::cout << variable << "[" << i << "]" << ": " << data.data[i] << std::endl;
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
