/*
 * That is the implementation source file for login class
 */

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#include "login.h"

//Constructor
Login :: Login() : userName(), password(){}

Login :: Login(const string& userName, const string& password) : userName(userName), password(password){}

//Accessor
string Login :: getUserName()const{
	return userName;
}

//Mutator
void Login :: setUserName(string newUserName){
	userName = newUserName;
}

void Login :: setPassword(string newPassword){
	password = newPassword;
}
