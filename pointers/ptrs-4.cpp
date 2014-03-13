#include <iostream>
#include <string>

using namespace std;

void getName(string &first, string &last);

int main(void)
{
    string first;
    string last;

    getName(first, last);
    cout << "First name: " << first << endl;
    cout << "Surname: " << last << endl;
}

void getName(string &first, string &last)
{
    cout << "Please enter first name: ";
    cin >> first;
    cout << "Please enter last name: ";
    cin >> last;
}
