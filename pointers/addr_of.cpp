#include <iostream>

using namespace std;

void foo(int &fucking_int)
{
	fucking_int += 500;
}

int main(void)
{
 	int a = 2;
	foo(a);
	cout << a << endl;
}
