#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string user1, user2;
    int age1, age2;
    cout << "Enter 2 users' names:" << endl;
    cout << "u1: ";
    getline(cin, user1, '\n');
    cout << "u2: ";
    cin >> user2;

    // ask for ages
    cout << "Enter age of " << user1 << ": ";
    cin >> age1;
    cout << "Enter age of " << user2 << ": ";
    cin >> age2;
    
    if(age1 > age2)
        cout << user1 << " is older than " << user2 << endl;
    else if(age1 < age2)
        cout << user1 << " is younger than " << user2 << endl;
    else
        cout << user1 << " is the same age as " << user2 << endl;
}
