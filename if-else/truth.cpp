#include <iostream>

using namespace std;

int main(void)
{
    if(1)
        cout << "1 is true" << endl;
    if(0)
        cout << "0 is true" << endl;
    if(550)
        cout << "550 is non-zero, therefore true" << endl;
    if(!0)
        cout << "!0 is as non-zero (and true) as it gets" << endl;
}
