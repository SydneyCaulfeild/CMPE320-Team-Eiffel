/*
 * That is the implementation source file for user class
 */

#include <iostream>
#include <string>
#include <stdlib.h>

#include "login.h"
#include "address.h"
#include "user.h"

using namespace std;

// constructors
User::User() {}

User::User(Login loginCreds) : loginCreds(loginCreds), volume(-1), currentLocation(Address(-1,-1,"null")), indoor(false), internet(false), power(false), equipment(false), maxTravelDistance(-1)  {}

User::User(int volume, Address currentLocation, bool indoor, bool internet, bool power, bool equipment, double maxTravelDistance, Login loginCreds) :
	volume(volume), currentLocation(currentLocation), indoor(indoor), internet(internet), power(power), equipment(equipment), maxTravelDistance(maxTravelDistance), loginCreds(loginCreds) {}

// accessors
int User::getVolume() {
	return volume;
}

Address User::getCurrentLocation() {
	return currentLocation;
}

bool User::getInternet() {
	return internet;
}

bool User::getPower() {
	return power;
}

bool User::getEquipment() {
	return equipment;
}

bool User::getIndoor() {
	return indoor;
}

double User::getMaxDistance() {
	return maxTravelDistance;
}

Login User::getLogin()
{
	return loginCreds;
}

// mutators
void User::setVolume(int volume) {
	this->volume = volume;
}
void User::setCurrentLocation(Address currentLocation) {
	this->currentLocation = currentLocation;
}

void User::setLogin(Login loginCreds) {
	this->loginCreds = loginCreds;
}

void User::setMaxDistance(double maxTravelDistance) {
	this->maxTravelDistance = maxTravelDistance;
}

void User::setIndoor(bool indoor) {
	this->indoor = indoor;
}

void User::setEquipment(bool equipment) {
	this->equipment = equipment;
}

void User::setPower(bool power) {
	this->power = power;
}

void User::setInternet(bool internet) {
	this->internet = internet;
}
