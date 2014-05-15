/**
 * a simple "log in" program, demonstrating use of maps
 *
 * EAS
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

/**
 * maps the users' usernames to their respective passwords
 */
map<string,string> db;

/**
 * attempts to log a user in. returns true if user exists with
 * this username and password, else false.
 */
bool login (string *username)
{
	string in_user;
	string in_pass;
	cout << "Please provide your username, then password:" << endl;
	cout << "username: ";
	cin >> in_user;
	cout << "password: ";
	cin >> in_pass;

	*username = in_user;
	map<string,string>::const_iterator itr = db.find(in_user);
	return (itr != db.end()) && (itr->second == in_pass);
}

/**
 * attempts to register the user in the system.  returns false iff
 * another user is already registered in the "db"
 */
bool reg_user ()
{
	string in_user;
	string in_pass;
	cout << "Please provide a username: ";
	cin >> in_user;
	map<string,string>::const_iterator itr = db.find(in_user);
	while (itr != db.end())
	{
		cout << "Username taken. Please provide another: ";
		cin >> in_user;
		itr = db.find(in_user);
	}

	cout << "Please provide a password: ";
	cin >> in_pass;

	db[in_user] = in_pass;
	return true;
}

/**
 * presents a menu to the user with two options
 * 1. register
 * 2. log in
 * 3. exit
 */
int stranger_menu ()
{
	int input;
	bool valid = false;
	do
	{
		cout << endl;
		cout << "What would you like to do?" << endl 
			<< "1. register" << endl
			<< "2. login" << endl
			<< "3. exit" << endl;
		cout << endl;
		cin >> input;	

		// validate that they chose option 1 - 3
		for (int i = 1; i <= 3; ++i)
			if (input == i)
				valid = true;	
	}
	while (!valid);

	return input;
}

void user_menu (const string &username)
{
	cout << "Hey, you're logged in..." << username << endl;
}

int main (void)
{
	bool done = false;

	do
	{
		int choice = stranger_menu();
		switch (choice)
		{
			case 1:
				reg_user();
				break;
			case 2:
			{
				string username;
				bool valid = login(&username);
				if (valid)
					user_menu(username);
				break;
			}
			case 3:
				done = true;
				break;
			default:
				break;
		}
	}
	while (!done);
}