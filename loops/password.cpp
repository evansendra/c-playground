#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
    int attempts = 0;
    bool correct = false;
    char* password = (char*)malloc(sizeof(char*));
    do
    {
        cout << "Enter password: ";
        cin >> password;
        if(strcmp(password, "wxyz") == 0)
            correct = true;
        attempts++;
    }
    while(!correct && attempts < 3);
    
    if(correct)
        cout << "Access granted" << endl;

    free(password);
}
