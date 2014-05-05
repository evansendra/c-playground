/**
 * demonstrates using a multi-dimensional (3d) array by filling
 * up some 3d multiplication tables and printing them out
 * 
 * Evan Sendra
 * 
 * [c++][practice][fun]
 */
#include <iostream>
#include <iomanip>
using namespace std;

void table_builder (int length, int width, int height);

int main (void)
{
	table_builder(0, 0, 0);
	cout << "========================" << endl;
	table_builder(3, 2, 1);
	cout << "========================" << endl;
	table_builder(5, 10, 15);
}

void table_builder (int length, int width, int height)
{
	// allocate space for the table and fill it
	int ***p_p_p_table = new int**[ length ];
	for (int l = 0; l < length; ++l)
	{
		p_p_p_table[ l ] = new int*[ width ];
		for (int w = 0; w < width; ++w)
		{
			p_p_p_table[ l ][ w ] = new int[ height ];
			for (int h = 0; h < height; ++h)
			{
				p_p_p_table[ l ][ w ][ h ] = (l*w*h);
			}
		}
	}	

	// print the table(s)
	for (int l = 0; l < length; ++l)
	{
		for (int w = 0; w < width; ++w)
		{
			for (int h = 0; h < height; ++h)
			{
				cout << setw(5) << p_p_p_table[ l ][ w ][ h ];	
			}
			cout << endl;
		}
		cout << endl;
	}

	// free da mem
	for (int l = 0; l < length; ++l)
	{
		for (int w = 0; w < width; ++w)
		{
			delete [] p_p_p_table[ l ][ w ];
		}
		delete [] p_p_p_table[ l ];
	}
	delete [] p_p_p_table;

}