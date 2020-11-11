#include "initialize.h"
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "location.h"

list<Location> Initialize::createList(char filePath[]) {
	list<Location> listOfLocations;
	int volume, maxCapacity, currentCapacity;
	bool internet, power, equipment;
	string locName, inOrOut;
	float longitude, latitude;

	// read text file containing location information separated by tabs
	ifstream inFile(filePath);
	string str;
	string delimiter = "\t";

	// read the file one line at a time
	while (getline(inFile, str)) {
		size_t pos = 0;
		string token;
		vector<string> attributes;
		while ((pos = str.find(delimiter)) != std::string::npos) {
		    token = str.substr(0, pos);
		    attributes.push_back(token);
		    str.erase(0, pos + delimiter.length());
		}
		attributes.push_back(str);
		locName = attributes[0];
		inOrOut = attributes[4];
		stringstream convert;
		convert << attributes[1];
		convert >> volume;
		convert.str("");
		convert.clear();
		convert << attributes[2];
		convert >> latitude;
		convert.str("");
		convert.clear();
		convert << attributes[3];
		convert >> longitude;
		convert.str("");
		convert.clear();
		convert << attributes[5];
		convert >> internet;
		convert.str("");
		convert.clear();
		convert << attributes[6];
		convert >> power;
		convert.str("");
		convert.clear();
		convert << attributes[7];
		convert >> equipment;
		convert.str("");
		convert.clear();
		convert << attributes[8];
		convert >> maxCapacity;
		convert.str("");
		convert.clear();
		convert << attributes[9];
		convert >> currentCapacity;
		Address address(longitude, latitude, locName);
		Location loc(volume, address, inOrOut, internet, power, equipment, maxCapacity, currentCapacity);
		listOfLocations.push_back(loc);
	}
	// sort the list of locations based on increasing longitude
	listOfLocations.sort();

	return listOfLocations;
}
