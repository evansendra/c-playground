#include <iostream>

using namespace std;

int main(void)
{
    int sum = 0;
    int tmp;
    do
    {
        cout << "To add (zero to quit): ";
        cin >> tmp;
        sum += tmp;
        cout << "Sum: " << sum << endl;
    }
    while (tmp != 0);
}
