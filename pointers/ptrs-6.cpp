/**
 * demo swap function using references
 *
 * eas
 */

#include <iostream>

using namespace std;

void swap(int &a, int &b);

int main(void)
{
    int a = 53;
    int b = 64;
    cout << "a: " << a << " b: " << b << endl;

    swap(a, b);

    cout << "a: " << a << " b: " << b << endl;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
