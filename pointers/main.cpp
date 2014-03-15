#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct Name 
{
    string first;
    string last;
};

void printName(Name &n);

int main()
{
    cout << "Hello world!" << endl;

    cout << "Please enter your full name: ";
    string name;
    getline(cin, name, '\n');

    Name person;
    person.first = "";
    person.last = "";
    bool on_first_name = true;
    for(int i = 0, l = name.length(); i < l; i++)
    {
        if(name[i] == ' ')
            on_first_name = false;
        else if(on_first_name)
            person.first += name[i];
        else
            person.last += name[i];
    }
    printName(person);

    return 0;
}

void printName(Name &n)
{
    cout << "First name is " << n.first << endl;
    cout << "Last name is " << n.last << endl;
}
