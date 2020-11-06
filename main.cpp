#include <iostream>
using namespace std;

#include "login.h"
#include "user.h"
#include "address.h"
#include "location.h"
#include <list>
#include <algorithm>

int main() {

	//For signup system
	string enteredPassword;
	string enteredUserName;
	Login newUser = Login();
	bool validity;
	
	cout << "Enter userName" << endl;
	cin >> enteredUserName;
	newUser.setUserName(enteredUserName);

	do {
		cout << "Enter password" << endl;
		cin >> enteredPassword;
		validity = newUser.checkValidity(enteredPassword);
	} while (!validity);

	newUser.setPassword(enteredPassword);
	
	


	list <User> users;	//not going to worry about user lookup efficiency since only need sample of users for proof of concept.
	User u1(Login("admin","Admin100")); User u2(Login("cisc320","McLeod123")); User u3(Login("anything","Anything1")); //Creating Users
	users.push_back(u1); users.push_back(u2); users.push_back(u3);	//Adding users to database
	User currentUser;
	User nullUser;	//null user will have no attributes set, a non-null user will have at least one attribute set => not equal to make sure logged in

	//user input
	string userName;
	string password;
	bool userExists = false;

	//not going to code user input yet because unsure of how UI will effect it.
	//theoretically it would go here

	//check if username is registered
	for (User const& i : users) {
		    if(((Login) (i.getLogin)).getUserName() == userName) {
		    	userExists = true;	//Validates credentials and assigns instance to correct user
		    }
		}

	//username exists
	if(userExists == true){
		Login enteredCreds = Login(userName,password);
			for (User const& i : users) {
			    if(i.getLogin == enteredCreds) {
			    	currentUser = i;	//Validates credentials and assigns instance to correct user
			    }
			}
			if(currentUser == nullUser) {	//incorrect password
				cout << "\nIncorrect Password!" << endl;
			}
	}

	while(currentUser != nullUser){
		//functionality available to user once logged in
	}


}



