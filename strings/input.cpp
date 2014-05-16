#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main (void)
{
	string input;
	cout << "Enter a multi-word line of text (using >> op) : ";
	// only grabs first word
	cin >> input;
	cout << "you typed: " << input << endl;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter a multi-word line of text (using getline) : ";
	// grabs full line
	string input2;
	getline (cin, input2, '\n');
	cout << "you typed: " << input2 << endl;
}