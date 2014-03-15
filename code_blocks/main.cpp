#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct name
{
    string first;
    string last;
};

void printName(name &n);

int main()
{
    cout << "Hello world!" << endl;

    cout << "Please enter your full name: ";
    string name;
    getline(cin, name, '\n');

    name person;
    bool on_first_name = true;
    for(int i = 0, l = name.length(); i < l; i++)
    {
        if(name[i] == ((char) " "))
            on_first_name = false;
        else if(on_first_name)
            person.first += name[i];
        else
            person.last += name[i];
    }
    printName(person);

    return 0;
}

void printName(name &n)
{
    cout << n.first << " " << n.last << endl;
}
