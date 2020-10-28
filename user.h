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
	User(int volume, Address currentLocation, string inOrOut, bool internet, bool power, bool equipment, double maxTravelDistance, Login loginCreds);

	// accessors
	int getVolume();
	Address getCurrentLocation();
	bool getInternet();
	bool getPower();
	bool getEquipment();
	string getInOrOut();
	double getMaxDistance();
	Login getLogin();

	// mutators
	void setVolume(int volume);
	void setCurrentLocation(Address currentLocation);
	void setLogin(Login LoginCreds);
	void setMaxDistance(double maxTravelDistance);
	void setInOrOut(string inOrOut);
	void setEquipment(bool equipment);
	void setPower(bool power);
	void setInternet(bool internet);

private:

	// attributes
	int volume;
	Address currentLocation;
	string inOrOut;
	bool internet;
	bool power;
	bool equipment;
	double maxTravelDistance;
	Login loginCreds;
};
