/*
 * That is the implementation source file for user class
 */

#include <iostream>
#include <string>
#include <stdlib.h>

#include "login.h"
#include "address.h"
#include "user.h"
#include "location.h"

using namespace std;

// constructors
User::User() {}

User::User(Login loginCreds) : loginCreds(loginCreds), volume(-1), currentLocation(Address(-1,-1,"null")), inOrOut("either"), internet(false), power(false), equipment(false), maxTravelDistance(-1), currentStudySpot(Address())  {}

User::User(int volume, Address currentLocation, string inOrOut, bool internet, bool power, bool equipment, double maxTravelDistance, Login loginCreds) :
	volume(volume), currentLocation(currentLocation), inOrOut(inOrOut), internet(internet), power(power), equipment(equipment), maxTravelDistance(maxTravelDistance), loginCreds(loginCreds), currentStudySpot(Address()) {}

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

string User::getInOrOut() {
	return inOrOut;
}

double User::getMaxDistance() {
	return maxTravelDistance;
}

Login User::getLogin() const
{
	return loginCreds;
}

Address User::getCurrentStudySpot()
{
	return currentStudySpot;
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

void User::setInOrOut(string inOrOut) {
	this->inOrOut = inOrOut;
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

void User::setCurrentStudySpot(Address currentStudySpot)
{
	this->currentStudySpot = currentStudySpot;
}

bool operator==(User left, User right) {
	return ((left.getVolume() == right.getVolume()) && (left.getPower() == right.getPower()) && (left.getInternet() == right.getInternet()) && (left.getEquipment() == right.getEquipment()) && (left.getLogin().equals(right.getLogin())) && (left.getInOrOut() == right.getInOrOut()) && (left.getMaxDistance() == right.getMaxDistance()) && (left.getCurrentLocation()  == right.getCurrentLocation()) && (left.getCurrentStudySpot() == right.getCurrentStudySpot()));
}

/*bool User::equals(User right) const {
	return ((this->getVolume() == right.getVolume()) && (this->getPower() == right.getPower()) && (this->getInternet() == right.getInternet()) && (this->getEquipment() == right.getEquipment()) && (this->getLogin().equals(right.getLogin())) && (this->getInOrOut() == right.getInOrOut()) && (this->getMaxDistance() == right.getMaxDistance()) && ((this->getCurrentLocation()).equals(right.getCurrentLocation())) && ((this->getCurrentStudySpot()).equals(right.getCurrentStudySpot())));
}*/



