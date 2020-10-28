#include <iostream>
using namespace std;

#include "login.h"
#include "user.h"
#include "address.h"
#include "location.h"
#include <list>
#include <algorithm>

int main() {
	list <User> users;	//not going to worry about user lookup efficiency since only need sample of users for proof of concept.
	User u1(Login("admin","Admin100")); User u2(Login("cisc320","McLeod123")); User u3(Login("anything","Anything1")); //Creating Users
	users.push_back(u1); users.push_back(u2); users.push_back(u3);	//Adding users to database
	User currentUser;

	//user input
	string userName;
	string password;

	//not going to code user input yet because unsure of how UI will effect it.
	//theoretically it would go here

	Login eneteredCreds = Login(userName,password);
	for (User const& i : users) {
	    if(i.getLogin == eneteredCreds) {
	    	User currentUser = i;	//Validates credentials and assigns instance to correct user
	    }
	}

	User nullUser;	//null user will have no attributes set, a non-null user will have at least one attribute set => not equal to make sure logged in
	while(currentUser != nullUser){
		//functionality available to user once logged in
	}


}



