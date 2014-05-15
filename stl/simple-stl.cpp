#include <iostream>
#include <map>
using namespace std;

void display_map (map<string, string> m)
{
	for (map<string, string>::iterator itr = m.begin();
		itr != m.end();
		++itr)
	{
		cout << itr->first << " -> " << itr->second
			<< endl;
	}

}

int main (void)
{
	map<string, string> addr_book;
	addr_book["Maggie"] = "margaritak@gmail.com";
	addr_book["Vojtěch"] = "vojtech@miksu.cz";
	addr_book["Evan"] = "evan@evansendra.com";

	display_map(addr_book);

	return 0;
}