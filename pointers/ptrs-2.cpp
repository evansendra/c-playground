#include <iostream>
#include <string>

using namespace std;

struct name
{
    string first;
    string last;
};

void getName(name &full_name);

int main(void)
{
    name person;
    name &first_person = person;
    getName(first_person);
    cout << "First name: " << person.first << endl;
    cout << "Surname: " << person.last << endl;
}

void getName(name& full_name)
{
    cout << "Please enter first name: ";
    cin >> full_name.first;
    cout << "Please enter last name: ";
    cin >> full_name.last;
}
