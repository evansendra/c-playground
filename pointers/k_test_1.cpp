#include <iostream>

using namespace std;

void foo(const char *a)
{
	a += 2;
}

void bar( const char * &a)
{
	a++;
	foo(a);
	a++;
}

int main(void)
{
	const char *x = "Real men code in C++";
	bar(x);
	cout << x << endl; 	   
}
