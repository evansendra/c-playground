/**
 * reads in HTML text (user-typed).
 * supports <html>, <head>, <body>, <b>, <i>,
 * and <a> tags in the following ways:
 *
 * <html>: throws the opening and closing html tags away, but
 * will aler the user if these are missing
 * <head>: removes this text (doesn't display it)
 * <body>: text to be displayed purposefully by the user
 * <b>: puts text in these tags in asterisks (e.g. *hello*)
 * <i>: surround this text with underscores (e.g. _hello_)
 * <a href=linkurl>text</a>: presents this link as text(linkurl)
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string parse_html (const string &input)
{
	// the output html
	string output;
	// indices for finding substrings
	string::size_type index1 = 0;
	string::size_type index2 = 0;
	// index of the current position
	string::size_type cur_pos = 0;

	index1 = input.find("<html>");
	index2 = input.find("</html>");

	// check if and where <html> starts the sequence
	if (index1 == string::npos || index2 == string::npos
		|| index2 < index1)
	{
		throw "Invalid HTML, <html> tag misplaced";
	}

	// move the cursor to where we found <html>
	cur_pos = index1 + string("<html>").length(); 

	// look for head tag
	if ( (index1 = input.find("<head>", cur_pos)) != string::npos &&
		 (index2 = input.find("</head>", cur_pos)) != string::npos &&
		 (index2 > index1))
	{
		cur_pos = index1 + string("<head>").length();
		string header = input.substr(cur_pos, index2 - cur_pos);

		cur_pos = index2 + string("</head>").length();  
		for (string::iterator itr = header.begin();
			itr != header.end();
			++itr)
		{
			*itr = toupper(*itr);	
		}
		output += header;
		output += "\n\n";
	}

	// TODO look for body tags, and display all text within, replacing 
	// supported tags with specified formatting

	return output;
}

int main (void)
{
	cout << "Please enter some HTML (<html><head><body><b><i><a> supported) "
		<< "to be parsed:" << endl;
	string input;
	getline (cin, input, '\n');

	try
	{
		cout << endl << parse_html(input);	
	}
	catch (const char *e)
	{
		cout << e << endl;
	}
}