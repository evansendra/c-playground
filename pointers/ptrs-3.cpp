#include <iostream>
#include <string>

using namespace std;

/*
struct name
{
    string first;
    string last;
};
*/

void getName(string *p_f, string *p_l);

int main(void)
{
    string *p_first = NULL;
    string *p_last = &l;

    getName(p_first, p_last);

    if(p_first != NULL)
        cout << "First name: " << *p_first << endl;
    if(p_last != NULL)
        cout << "Surname: " << *p_last << endl;
}

void getName(string *p_f, string *p_l)
{
    if(p_f != NULL)
    {
        cout << "Please enter first name: ";
        getline(cin, *p_f, '\n');
    }

    if(p_l != NULL)
    {
        cout << "Please enter last name: ";
        getline(cin, *p_l, '\n');
    }
}
