#include <iostream>

using namespace std;

void swap(int *a, int *b);

int main(void)
{
    int x = 5;
	int y = 32;

	int *p_x = &x;
	int *p_y = &y;

	cout << "x: " << x << " y: " << y << endl;
	swap(p_x, p_y);
	cout << "x: " << x << " y: " << y << endl;
}

void swap(int *p_a, int *p_b)
{
	int tmp = *p_a;
	*p_a = *p_b;
	*p_b = tmp;
}
