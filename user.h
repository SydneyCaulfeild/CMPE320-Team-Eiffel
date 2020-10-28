/*
 * Header file for user
 */

#pragma once

#include <iostream>
#include <string>
#include "login.h"
#include "address.h"

using namespace std;

class User {

public:

	// constructors
	User(); //null instance
	User(Login loginCreds);
	User(int volume, Address currentLocation, bool indoor, bool internet, bool power, bool equipment, double maxTravelDistance, Login loginCreds);

	// accessors
	int getVolume();
	Address getCurrentLocation();
	bool getInternet();
	bool getPower();
	bool getEquipment();
	bool getIndoor();
	double getMaxDistance();
	Login getLogin();

	// mutators
	void setVolume(int volume);
	void setCurrentLocation(Address currentLocation);
	void setLogin(Login LoginCreds);
	void setMaxDistance(double maxTravelDistance);
	void setIndoor(bool indoor);
	void setEquipment(bool equipment);
	void setPower(bool power);
	void setInternet(bool internet);

private:

	// attributes
	int volume;
	Address currentLocation;
	bool indoor;
	bool internet;
	bool power;
	bool equipment;
	double maxTravelDistance;
	Login loginCreds;
};
