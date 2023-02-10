//============================================================================
// Name        : Warzone.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "Map.h"
#include <fstream>
#include <sstream>
using namespace std;


int main()
{
	// --------------------- Introduction ---------------------//
	cout << "Welcome to COMP 345 Assignment #1" << endl;

	//Storing name of file to pull data from:
	cout << "\nPlease enter the name of the file:" << endl;
	string input_file_name;
	cin >> input_file_name;

	// --------------------- Initializing Map ---------------------//
	Map myMap;
	myMap.setFileName(input_file_name);


	// --------------------- Pulling data from file ---------------------//

	ifstream myFile;
	myFile.open(input_file_name);
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

						myMap.addContinent(continent);
					}
				}

				//Storing number of continents
				myMap.setNumOfContinents(count);

				//To keep scanning the file for next line to fill countries info
				endLoop = false;
			}



			//When [countries] headline is met --> *** store countries ***
			if (temp.find("[countries]") != std::string::npos)
			{
				//resetting count
				count = 0;

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
						territory.setX_coordinate(stoi(tokens[3]));
						territory.setY_coordinate(stoi(tokens[4]));

						myMap.addTerritory(territory);
					}
				}
				//Storing number of territories
				myMap.setNumOfTerritories(count);

				//To keep scanning the file for next line to fill countries info
				endLoop = false;
			}



			//When [borders] headline is met --> *** store borders info ***
			if (temp.find("[borders]") != std::string::npos)
			{
				//resetting count
				count = 0;

				//Initializing the map graph
				myMap.initializeMap();

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
						for(int y = 0; y < tokens.size()-1; y++)
						{
							count++;
							myMap.addAdjacentTerritoryBorder(territory_id, stoi(tokens[count]));
						}
					}
				}

				//To keep scanning the file for next line to fill countries info
				endLoop = false;
			}
		}
	}

	//Showing the data stored for validation purposes
	myMap.printContinents();
	myMap.printTerritories();
	myMap.printAdjacentTerritoryBorders();
	cout << "\nEnd of Program!";



	return 0;
}
