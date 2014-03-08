#include <iostream>
#include <string>

using namespace std;

enum Color
{
    GREEN = 0, BLUE = 1, YELLOW = 2
};

int main(void)
{
    // get string from the user
    string input;
    cin >> input;

    Color color = YELLOW;

    if(input == "foo")
        color = GREEN;
    else if(input == "bar")
        color = BLUE;

    switch(color)
    {
        case GREEN:
            cout << "\033[1;32mYou chose green!\033[1;0m" << endl;
            break;
        case BLUE:
            cout << "\033[1;34mSO BLUE!\033[1;0m" << endl;
            break;
        case YELLOW:
            cout << "\033[1;33mo hai im yello\033[1;0m" << endl;
            break;
        default:
            cout << "\033[1;36mhow ugly is cyan?\033[1;0m" << endl;
            break;
    }

}
