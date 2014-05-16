#include <iostream>
#include <ctime>
#include <map>

using namespace std;

void display_map (const map<string,string> &data)
{
	for (map<string,string>::const_iterator itr = data.begin();
		itr != data.end();
		++itr)
	{
		cout << itr->first << " -> " << itr->second << endl;			
	}	
}

void display_map_copy (map<string,string> data)
{
	for (map<string,string>::const_iterator itr = data.begin();
		itr != data.end();
		++itr)
	{
		cout << itr->first << " -> " << itr->second << endl;			
	}	
}

int main (void)
{
	map<string,string> addrs = {{"Evan", "evan@evansendra.com"},
						{"Maggie", "mk@gmail.com"},
						{"Vojtech", "v@m.cz"}
						};
	for (int i = 0; i < 10000; ++i)
	{
		char c = i;
		string key = "foo" + c % 255;
		addrs[key] = "asdfkla;jsdjklfalskdj;fa4klsdjflkasjdfkajsdlkfjaskldjf";
	}

	clock_t begin = clock();

	display_map(addrs);

	clock_t end = clock();

	double delta1 = (double)(end - begin) / (double)CLOCKS_PER_SEC;

	begin = clock();
	display_map_copy(addrs);
	end = clock();

	double delta2 = (double)(end - begin) / (double)CLOCKS_PER_SEC;
	cout << endl << endl;
	cout << "without copy: " << delta1 << endl;
	cout << "with copy: " << delta2 << endl;

}