#include "MapLoader.h"
#include "Territory.h"
#include "Continent.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

MapLoader::MapLoader(): map()
{
	mapFileName = "null";
}

MapLoader::MapLoader(string fileName): map()
{
	mapFileName = fileName;
}




Map MapLoader::loadMap()
{

	// --------------------- Checking if file exists ---------------------//
	ifstream myFile;
	myFile.open(mapFileName);
	if (myFile.good() == 0)
	{
		//Returning Failure
		cout << "\nMap failed to load! Please make sure that file exists" << endl;
		return map;
	}

	//temp variable to store the context of each line in file:
	string temp;

	//temp variable to count how many countries and continents;
	int count = 0;

	//If input file is open and valid:
	if (myFile.is_open())
	{
		//endloop variable to end the while loop when all the countries have been stored
		bool endLoop = false;

		//While text file still lines and the countries data have not yet been reached
		while(getline(myFile, temp) && endLoop == false)
		{


			// --------------------- Storing territories  ---------------------//

			//When [continents] headline is met --> *** store continents ***
			if (temp.find("[continents]") != std::string::npos)
			{
				//resetting count
				count = 0;

				//Storing data of continents
				while(getline(myFile, temp) && endLoop == false)
				{
					//skip one more line if there is a note (line starting with ';')
					if(temp.substr(0, 1) == ";")
						getline(myFile, temp);

					//Stop the loop when no more continents (empty line)
					if(temp.size() == 1)
					{
						endLoop = true;
					}
					else
					{
						//counting how many continents
						count++;

						//Storing the 3 words separated by white spaces from temp into a tokens vector
						//Continents format:
						//EX:   Scandinavia       5           #fff780
						//        [name]   [continent_id]    [color]
						string buf;
						stringstream ss(temp);
						vector<string> tokens;

						//while there is more tokens
						while (ss >> buf)
						{
							tokens.push_back(buf);
						}

						//Storing the different tokens (continents info) inside the Map class
						Continent continent;
						continent.setName(tokens[0]);
						continent.setId(stoi(tokens[1]));
						continent.setColor(tokens[2]);

						map.addContinent(continent);
					}
				}

				//Storing number of continents
				map.setNumOfContinents(count);

				//To keep scanning the file for next line to fill countries info
				endLoop = false;
			}




			// --------------------- Storing Continents  ---------------------//

			//When [countries] headline is met --> *** store countries ***
			if (temp.find("[countries]") != std::string::npos)
			{
				//resetting count
				count = 0;

				//Initializing the continents graph
				map.initializeTerritoriesInContinentsGraph();

				//Storing data of countries
				while(getline(myFile, temp) && endLoop == false)
				{
					//skip one more line if there is a note (line starting with ';')
					if(temp.substr(0, 1) == ";")
						getline(myFile, temp);

					//Stop the loop when no more countries (empty line)
					if(temp.size() == 1)
					{
						endLoop = true;
					}
					else
					{
						//counting how many continents
						count++;

						//Storing the 5 words separated by white spaces from temp into a tokens vector
						//Countries format:
						//EX:   1   Reykjavik       1          27        30
						//    [id]   [name]   [continent_id] [x_coor] [y_coor]
						string buf;
						stringstream ss(temp);
						vector<string> tokens;

						//while there is more tokens
						while (ss >> buf)
						{
							tokens.push_back(buf);
						}

						//Storing the different tokens (countries info) inside the Map class
						Territory territory;
						territory.setTerritory_id(stoi(tokens[0]));
						territory.setTerritory_name(tokens[1]);
						territory.setContinent_id(stoi(tokens[2]));

						map.addTerritory(territory);

						//storing the continent of territory
						int cont_id = stoi(tokens[2]);
						map.addTerritoryToContinent(cont_id, territory);
					}
				}
				//Storing number of territories
				map.setNumOfTerritories(count);

				//To keep scanning the file for next line to fill countries info
				endLoop = false;
			}




			// --------------------- Storing Borders  ---------------------//

			//When [borders] headline is met --> *** store borders info ***
			if (temp.find("[borders]") != std::string::npos)
			{
				//resetting count
				count = 0;

				//Initializing the adjacent territories graph
				map.initializeAdjacentTerritoriesGraph();

				//Storing data of borders
				while(getline(myFile, temp) && endLoop == false)
				{
					//resetting count
					count = 0;

					//skip one more line if there is a note (line starting with ';')
					if(temp.substr(0, 1) == ";")
						getline(myFile, temp);

					//Stop the loop when no more borders (empty line)
					if(temp.size() == 1)
					{
						endLoop = true;
					}
					else
					{
						//Storing the shared borders from each line
						//Borders format:
						//EX:   10                     8   9   11
						//     [country_id]   [...other countries_id that have border]
						string buf;
						stringstream ss(temp);
						vector<string> tokens;

						//while there is more tokens
						while (ss >> buf)
						{
							tokens.push_back(buf);
						}

						//Finding the right matching territory that we are adding a border to
						int territory_id = stoi(tokens[0]);

						//Storing the different tokens (Borders info) inside the Map class
						for(int y = 1; y < tokens.size(); y++)
						{
							int destination_territory = stoi(tokens[y]) - 1;
							map.addAdjacentTerritoryBorder(territory_id, map.getTerritories()[destination_territory]);
						}
					}
				}

				//To keep scanning the file for next line to fill countries info
				endLoop = false;
			}
		}
	}

	//Returning success
	cout << "\nMap successfully loaded!" << endl;
	return map;
}


//Getters
string MapLoader::getFileName()
{
	return mapFileName;
}



//Setters
void MapLoader::setFileName(string name)
{
	mapFileName = name;
}
