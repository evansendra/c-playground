#include <iostream>
#include <set>

using namespace std;

/**
 * returns false if the character is not whitespace,
 * not an alphabet character, and not a digit according
 * to the ascii table
 */
bool isNormalChar (char c)
{
	return ((c >= 48) && (c <= 57)) // is it a digit
		|| ((c >= 65) && (c <= 90)) // is it upper-case letter
		|| ((c >= 97) && (c <= 122)) // is it lower-case letter
		|| (c == 32); // is it whitespace
}

string get_input_line ()
{
	cout << "Please enter a line of text separated by an "
		<< "arbitrary character." << endl;
	string input;
	getline (cin, input, '\n');
	return input;
}

int main (void)
{
	string in = get_input_line();	

	// characters suspected to be separators
	set<char> suspects;
	for (string::size_type i = 0; i < in.length(); ++i)
	{
		// add special chars to suspected separators
		if ( !isNormalChar(in[ i ]) )
			suspects.insert(in[ i ]);
	}

	// get one more line of text to detect what separators
	// are possible
	in = get_input_line();
	set<char> final_suspects;
	for (string::size_type i = 0; i < in.length(); ++i)
	{
		set<char>::iterator itr = suspects.find(in[i]);
		// if the character was in the first round of suspects, insert it
		// into this set too
		if (itr != suspects.end())
			final_suspects.insert(in[i]);
	}

	// ask user which special char is the separator if there is one
	if (final_suspects.size() == 0)
	{
		cout << "Sorry, no separator detected!" << endl;
		return 0;
	}
	else if (final_suspects.size() == 1)
	{
		char separator;
		for (set<char>::const_iterator itr = final_suspects.begin();
			itr != final_suspects.end();
			++itr)
		{
			separator = *itr;
		}
		cout << "Okay, we'll use the " << separator << " separator." << endl;
		return 0;
	}
	else
	{
		cout << "Which of these is your separator:" << endl;
		for (set<char>::const_iterator itr = final_suspects.begin();
			itr != final_suspects.end();
			++itr)
		{
			cout << *itr << endl;
		}
	}


	char in_char;
	cin >> in_char;
	if (final_suspects.find(in_char) == final_suspects.end())
	{
		cout << "Cannot use that separator!" << endl;
		return 0;
	}
	else
	{
		cout << "Okay, we'll use the " << in_char << " separator" << endl;
	}

}