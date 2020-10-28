/*
 * Header file for location
 */

#pragma once

#include <iostream>
#include <string>
#include "user.h"

using namespace std;

class Location {

public:

	// constructors
	Location();
	Location(int volume, Address location, bool indoor, bool internet, bool power, bool equipment, int maxCapacity, int currentCapacity);

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
	void setInternet(bool internet);
	void setPower(bool power);
	void setEquipment(bool equipment);
	void setIndoor(bool indoor);
	void setMaxCapacity(int maxCapacity);
	void setCurrentCapacity(int currentCapacity);

	bool checkPreferences(User user);

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
