#include <iostream>

using namespace std;

int main(void)
{
    int input;
    cout << "Enter password: ";
    cin >> input;
    if(input == 1234 || input == 54321)
    {
        cout << "Access granted!" << endl;
    }
    else
    {
        cout << "Incorrect. Exiting." << endl;
        return 1;
    }
}
