/*
 * File: Location.h
 * Date: Oct 24, 2020
 * Author: Shiyan Boxer, Sean Pollen
 * Description: Location cpp file
 * Attributes:
    * location: Address
    * maxCapacity: int
    * currentCapacity: int
    * inOrOut: string
    * internet: bool
    * volume: int
    * power: bool
    * equipment: bool
* Methods
    * checkPreferences(User):
    * getMaxCapacity(): int
    * getCurrentCapacity(): int
    * getInOrOut(): string
    * getInternet():bool
    * getVolume(): int
    * getPower(): bool
    * getEquipment(): int
    * getLocation(): string
    * seMaxCapacity():
    * setCurrentCapacity():
    * setInOrOut():
    * setInternet():
    * setVolume():
    * setPower():
    * setEquipment():
    * setLocation():
 */
/*

toDo
- change mutators in .h to void
- write check user preference method
*/

// Include libraries
#include <time.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <iostream>
#include <fstream>
#include <string>

// Include insult location.h and address.h files
#include "location.h"
#include "address.h"
#include "user.h"

using namespace std;

// Constructors
Location::Location() : volume(), location(), inOrOut(), internet(), power(), equipment(), maxCapacity(), currentCapacity() {}
Location::Location(int volume, Address location, string inOrOut, bool internet, bool power, bool equipment, int maxCapacity, int currentCapacity)
{
    this->volume = volume;
    this->location = location;
    this->inOrOut = inOrOut;
    this->internet = internet;
    this->power = power;
    this->equipment = equipment;
    this->maxCapacity = maxCapacity;
    this->currentCapacity = currentCapacity;
}
// Accessor
int Location::getVolume() {
    return volume;
}

Address Location::getLocation() {
    return location;
}

bool Location::getInternet() {
    return internet;
}

bool Location::getPower() {
    return power;
}

bool Location::getEquipment() {
    return equipment;
}

string Location::getInOrOut() {
    return inOrOut;
}

int Location::getMaxCapacity() {
    return maxCapacity;
}

int Location::getCurrentCapacity()
{
    return currentCapacity;
}

// Mutators
void Location::setInternet(bool internet) {
    this->internet = internet;
}

void Location::setPower(bool power) {
    this->power = power;
}

void Location::setEquipment(bool equipment) {
    this->equipment = equipment;
}

void Location::setInOrOut(string inOrOut)
{
    this->inOrOut = inOrOut;
}

void Location::setMaxCapacity(int maxCapacity)
{
    this->maxCapacity = maxCapacity;
}

void Location::setCurrentCapacity(int currentCapacity)
{
    this->currentCapacity = currentCapacity;
}

bool Location::operator<(const Location& right)
{
	Address addr1 = this->location;
	Address addr2 = right.location;
	return addr1.getLongitude() < addr2.getLongitude();
}

// Check user preferences method, returns true if the study spot is valid to add to the list
bool Location::checkPreferences(User user) {
    //check all the boolean variables, statement is true if every variable matches
    if (user.getEquipment() == this->equipment
        && user.getInOrOut() == this->inOrOut
        && user.getInternet() == this->internet
        && user.getPower() == this->power
        && user.getVolume() >= this->volume
        && this->currentCapacity < this->maxCapacity) {
        float temp = user.getCurrentLocation().calculateDistance(this->getLocation().getLongitude(), this->getLocation().getLatitude(),
        		user.getCurrentLocation().getLongitude(), user.getCurrentLocation().getLatitude()); //this function must be overloaded to the address class
        if (temp <= user.getMaxDistance())
            return true; // a location exists that meets requirements and is within a valid distance
        return false; //the location is too far
    }
    return false; //nothing meets the requirements
}
