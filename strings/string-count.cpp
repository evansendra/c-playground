/**
 * counts the number of times a specified substring ('needle') is found
 * in another, larger string ('haystack')
 */

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main (void)
{
	string needle;
	string haystack;

	cout << "Please give me a word to search for.  Then, give me a "
		<< " a larger piece of text in which to search for the first word."
		<< endl;
	cout << "The word:" << endl;
	cin >> needle;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "The paragraph in which to search:" << endl;
	getline(cin, haystack, '\n');

	unsigned count = 0;
	for (string::size_type idx = haystack.find(needle);
		idx != string::npos;
		idx = haystack.find(needle, idx + needle.length()))
	{
		++count;
	}

	cout << "Found " << needle << " in the paragraph " << count << " times." << endl;
	return 0;
}
