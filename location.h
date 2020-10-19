/*
 * Header file for location
 */

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Location {

public:

	// constructors
	Location();
	Location(int volume, Address location, bool indoor,	bool internet, bool power, bool equipment, int maxCapacity, int currentCapacity);

	// accessors
	int getVolume();
	Address getLocation();
	bool getInternet();
	bool getPower();
	bool getEquipment();
	bool getIndoor();
	int getMaxCapacity();
	int getCurrentCapacity();

	// mutators
	bool setInternet(bool internet);
	bool setPower(bool power);
	bool setEquipment(bool equipment);
	bool setIndoor(bool indoor);
	int setMaxCapacity(int maxCapacity);
	int setCurrentCapacity(int currentCapacity);

	void checkPreferences(User user);

private:

	// attributes
	int volume;
	Address location;
	bool indoor;
	bool internet;
	bool power;
	bool equipment;
	int maxCapacity;
	int currentCapacity;
};