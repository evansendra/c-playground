#include <iostream>

using namespace std;

int main(void)
{
    for(int i = 99; i > 0; i--)
    {
        cout << i << " bottles of beer on the wall, " << i
        << " bottles of beer." << endl << "Take one down, pass it around, "
        << (i-1) << " bottles of beer on the wall." << endl << endl;
    }
}
