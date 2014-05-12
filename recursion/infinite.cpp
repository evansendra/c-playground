#include <iostream>
using namespace std;

/**
 * surprise! This is going to cause stackoverflow
 */
void recurse(unsigned count)
{
	cout << count << endl;
	recurse(count + 1);
}

int main (void)
{
	recurse(1);
}