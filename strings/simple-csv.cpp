#include <iostream>
#include <string>

using namespace std;

int main (void)
{
	while (1)
	{
		cout << "Enter the input <first_name>, <last_name>, <friend_status>"
			<< endl;
		string first_name;
		getline (cin, first_name, ',');

		if (first_name.size() == 0)
			break;

		string last_name;
		getline (cin, last_name, ',');

		string friend_status;
		getline (cin, friend_status, '\n');

		cout << first_name << " " << last_name << " is " 
			<< friend_status << endl;
		cout << endl << endl;
	}	
}