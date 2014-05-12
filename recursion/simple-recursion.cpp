#include <iostream>
using namespace std;

void print_num (int num)
{
	cout << num << " ";
	if (num < 10)
		print_num (num + 1);
	cout << num << " ";
}

int main (void)
{
	print_num(1);
	cout << endl;
}