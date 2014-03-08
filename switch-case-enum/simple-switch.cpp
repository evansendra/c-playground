#include <iostream>

using namespace std;

int main(void)
{
    int input;
    cout << "Please enter a number..." << endl
    << "0 for green text" << endl
    << "1 for blue text" << endl
    << "2 for yellow text" << endl;

    cin >> input;
    switch(input)
    {
        case 0:
            cout << "\033[1;32m" << "You chose green!" << "\033[1;0m" << endl;
            break;
        case 1:
            cout << "\033[1;34m" << "SO BLUE" << "\033[1;0m" << endl;
            break;
        case 2:
            cout << "\033[1;33m" << "o, hai im yello" << "\033[1;0m" << endl;
            break;
        default:
            cout << "\033[1;36m" << "How ugly is cyan?" << "\033[1;0m" << endl;
            break;
    }
}
