#include <iostream>
#include <string>
using namespace std;
/**
 * lets users keep track of the last time they talked to each of their 
 * friends, which can be added on-the-fly, and displays a the last time
 * each the user talked to each friend
 */

/*
 * a "friend" with a name and days_ago (days since spoken to)
 */
struct Friend
{
	string name;
	unsigned days_ago;
};

struct Arr
{
	Friend* p_friends;
	int elements;
	int size;
};

/*
 * allows the user to add a friend to the list of friends
 * returns false if the friend already exists, else true
 */
bool add_friend (const string &name, const unsigned days_ago);

/*
 * allows the user to set the time he last talked to his friend
 * returns false if friend doesn't exist, else true
 */
bool last_talked (const string &name, const unsigned &days_ago);

/**
 * displays the user's list of friends with the days since the 
 * user spoke with that friend
 */
void show_friends ();

/**
 * grows the array p_array of size size, where it is assumed the size
 * is equal to the number of elements in the array
 */
void grow_array (Arr *array);

/*
 * dipslays a menu which returns an integer - users choice of what to do:
 * 1 - add a friend
 * 2 - set time I last talked to a friend
 * 3 - display list of friends and when we last spoke
 * 4 - exit 
 */
int menu ();

/**
 * clears all the memory used in order to make the friend list
 */
void destroy_friend_list ();

// global friend list
Arr friend_list;

int main (void)
{
	// init the global friend list
	friend_list.p_friends = new Friend[ 5 ];
	friend_list.elements = 0;
	friend_list.size = 5;

	int choice;
	do
	{
		choice = menu();
		string input_name = "";
		int input_days = 0;
		bool ret = false;
		switch (choice)
		{
			case 1:
			{
				cout << "What's the friend's name?" << endl;
				cin >> input_name;
				cout << "When you last spoke?" << endl;
				cin >> input_days;
				ret = add_friend(input_name, input_days);
				if (!ret)
					cout << "Sorry, couldn't add " << input_name << endl;
				break;
			}
			case 2:
			{
				input_name = "";
				input_days = 0;
				cout << "Which friend?" << endl;
				cin >> input_name;
				cout << "When you last talked?" << endl;
				cin >> input_days;
				ret = last_talked(input_name, input_days);
				if (!ret)
				{
					cout << "Sorry, couldn't set " << input_name << " with " << input_days
						<< " days" << endl;
				}
				break;
			}
			case 3:
				show_friends();
				break;
			case 4:
				break;
		}
	}
	while (choice != 4);

	destroy_friend_list();
}

bool add_friend (const string &name, const unsigned days_ago)
{
	// check if the friend already exists in the friend list
	for (int i = 0; i < friend_list.elements; ++i)
	{
		if (friend_list.p_friends[ i ].name == name)
			return false;
	}

	// check if we need to grow the array
	if (friend_list.elements == friend_list.size)
		grow_array(&friend_list);

	// we can now add the friend to the end of the list
	friend_list.p_friends[ friend_list.elements ].name = name;
	friend_list.p_friends[ friend_list.elements ].days_ago = days_ago;
	++friend_list.elements;
	return true;
}

void grow_array (Arr *array)
{
	int newsize = array->size * 1.5;
	Friend *tmp = new Friend[ newsize ];

	for (int i = 0; i < array->elements; ++i)
		tmp[ i ] = array->p_friends[ i ];

	delete [] array->p_friends;
	array->p_friends = tmp;
}

void destroy_friend_list ()
{
	delete [] friend_list.p_friends;
}

bool last_talked (const string &name, const unsigned &days_ago)
{
	for (int i = 0; i < friend_list.elements; ++i)
	{
		if (name == friend_list.p_friends[ i ].name)
		{
			friend_list.p_friends[ i ].days_ago = days_ago;	
			return true;
		}
	}

	return false;
}

void show_friends ()
{
	for (int i = 0; i < friend_list.elements; ++i)
	{
		cout << friend_list.p_friends[ i ].name << " : " << friend_list.p_friends[ i ].days_ago << endl;
	}
}

int menu ()
{
	int choice = 0;
	do 
	{
		cout << "What would you like to do?" << endl;
		cout << "1 - add a friend" << endl;	
		cout << "2 - set time I last talked to a friend" << endl;	
		cout << "3 - show my list of friends" << endl;	
		cout << "4 - exit" << endl;
		cin >> choice;
	}
	while (choice < 1 && choice > 4);
	return choice;
}