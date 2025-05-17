#include "MapLoader.h"
#include <fstream>
#include <string>

void MapLoader::saveNew(std::string filename)
{
	std::ofstream file;

	file.open("assets/maps/" + filename);
	file << "write this whole thing" << std::endl;
	file.close();
}

void MapLoader::load(std::string filename)
{
	std::ifstream file("assets/maps/" + filename);
	std::string lineBuffer;

	bool readingMap = false;
	bool mapEnds = false;
	bool mapHasEnded = false;
	if (file.is_open())
	{
		while (std::getline(file, lineBuffer))
		{
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

			if (readingMap && lineBuffer != "|Map|" && lineBuffer != "|~Map|" && !mapHasEnded)
			{
				int variable = lineBuffer.find('=');
				int endLine = lineBuffer.find("~");

				// Variable
				std::cout << lineBuffer.substr(0, variable) << std::endl;

				variable++; // Get rid of the equality sign 

				// Value
				std::cout << lineBuffer.substr(variable, endLine - variable) << std::endl;
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
