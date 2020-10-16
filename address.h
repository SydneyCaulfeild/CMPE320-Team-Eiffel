/*
 * That is the header file for address
 */

#pragma once

#include<iostream>
#include <string>

using namespace std;

class Address{

public:

	Address(); //Default Constructor
	Address(string longtitude, string lattitude, string addressName); //Constructor
	string getLongtitude()const; //Accessor to return longtitude
	string getLattitude()const; //Accessor to return lattitude
	string getAddressName()const; //Accessor to return address name

	void setLongtitude(string longtitude); //Mutator to set the longtitude
	void setLattitude(string lattitude); //Mutator to set the lattitude
	void setAddressName(string addressName); //Mutator to set the address name

	double calculateDistance(const Address& address1, const Address& address2); //Method to calculate the distance between the two addresses
	void printAddress(string longtitude, string lattitude, string addressName); //Method to print address

private:
	string longtitude;
	string lattitude;
	string addressName;
};
