#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string user1, pass1;
    string user2, pass2;

    cout << "Provide first user/pass: " << endl << "user1: ";
    cin >> user1;
    cout << "pass1: ";
    cin >> pass1;
    cout << "Provide second user/pass: ";
    cout << "user2: ";
    cin >> user2;
    cout << "pass2: ";
    cin >> pass2;

    if(user1 == "foo" && pass1 == "bar")
        cout << user1 << " logged in." << endl;
    if(user2 == "baz" && pass2 == "qux")
        cout << user2 << " logged in." << endl;
}
