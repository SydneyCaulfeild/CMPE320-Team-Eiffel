/*
 * That is the implementation source file for login class
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>



using namespace std;

#include "login.h"

//Constructor
Login :: Login() : userName(), password(){}

Login :: Login(const string& userName, const string& password) : userName(userName), password(password){}

//Accessor
string Login::getUserName()const {
	return userName;
}

//Mutator
void Login :: setUserName(string newUserName){
	userName = newUserName;
}

void Login :: setPassword(string newPassword){
	password = newPassword;
}

void Login::checkValidity(string enteredPassword)
{
	bool length = false, digit = false, upperCase = false, lowerCase = false;

	if (enteredPassword.length() >= 7) {
		length = true;
	}

	char password[enteredPassword.length()];
	strcpy(password, enteredPassword.c_str());
	for (int i = 0; i < enteredPassword.length(); i++) {
		char c = password[i];
		if (!digit && isdigit(c)) {
			digit = true;
			continue;
		}

		if (!upperCase && isupper(c)) {
			upperCase = true;
			continue;
		}

		if (!lowerCase && islower(c)) {
			lowerCase = true;
			continue;
		}
	}

	cout << "Password Length : " << (length ? "Long Enough" : "Too Short");
	cout << "Password contains digit ? : " << (digit ? "Yes" : "No");
	cout << "Password contains upper case ? : " << (upperCase ? "Yes" : "No");
	cout << "Password contains lower case ? : " << (lowerCase ? "Yes" : "No");

	if(length == true && digit == true && upperCase == true && lowerCase == true) {
		valid = true;
		cout << "Password is valid ? : " << (valid ? "Yes" : "No");
		return true;
	} else {
		cout << "Password is valid ? : " << (valid ? "Yes" : "No");
		return false;
	}


}
