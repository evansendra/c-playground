#include <iostream>

using namespace std;

int main(void)
{
    int x;
    cout << "What's in x: " << x << endl;
    int *p_x = &x;
    cout << "What's the address of x: " << p_x << endl;
    *p_x = 5;
    cout << "What's p_x pointing to: " << *p_x << endl;
    cout << "Now what's in x: " << x << endl;
}
