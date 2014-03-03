#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void)
{
    char *name = (char*)malloc(sizeof(char*));
    cout << "What's your name: ";
    cin >> name;
    cout << "Hi, " << name << endl;
    free(name);
    return 0;
}
