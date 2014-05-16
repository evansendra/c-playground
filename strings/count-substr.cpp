#include <iostream>
#include <string>

using namespace std;

int main (void)
{
	string input;
	cout << "please give us a string: ";
	getline (cin, input, '\n');

	string to_search_for = "isc";

	int count = 0;
	string::size_type i = 0;
	for (i = input.find(to_search_for, 0);
		i != string::npos;
		i = input.find(to_search_for, ++i))
	{
		++count;
	}

	cout << "'isc' was found " << count << " times in the input" << endl;
}