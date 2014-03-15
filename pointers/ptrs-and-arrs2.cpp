#include <iostream>
#include <string>

using namespace std;

void printArr(string &arr, int length);

int main(void)
{
    int length = 30;
    string *names = new string[ length ];   
    int cur_elem = 0;
    string name;
    do
    {   
        cout << "Input a name please (or exit): ";
        cin >> name;
        if(name != "exit")
            names[ cur_elem++ ] = name;
    }
    while(name != "exit");
    string &r_names = names;
    printArr(r_names , length);
}

void printArr(string &arr, int length)
{
    for(int i = 0; i < length; i++)
        cout << "array[ " << i << " ] = " << arr[i] << endl;
}
