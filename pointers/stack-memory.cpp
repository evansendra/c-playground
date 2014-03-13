#include <iostream>

using namespace std;

int main(void)
{
    int a;
    int foo[100];
    int b;

    cout << "a: " << &a << endl;
    for(int i = 0; i < 100; i++)
        cout << "foo[" << i << "]: " << &foo[i] << endl;

    cout << "b: " << &b << endl;
}
