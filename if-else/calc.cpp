#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string operation;
    int a, b;
    cout << "Which operation?" << endl;
    cin >> operation;
    cout << "Enter arguments: " << endl;
    cout << "arg1: ";
    cin >> a;
    cout << "arg2: ";
    cin >> b;
    if(operation == "add")
    {
        cout << a + b << endl;
    }
    else if(operation == "sub")
    {
        cout << a - b << endl;
    }
    else if(operation == "mul")
    {
        cout << a * b << endl;
    }
    else if(operation == "div")
    {
        cout << a / b << endl;
    }
    else
    {
        cout << "Supported ops: add, sub, mul, div. Exiting." << endl;
    }
    return 0;
}
