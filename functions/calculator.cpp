#include <iostream>

using namespace std;

int add(int x, int y);
int sub(int x, int y);
double div(int x, int y);
int mul(int x, int y);

int main()
{
    while(true)
    {
        int a;
        int b;
        string command;

        cout << "What would you like to do?" << endl
            << "add" << endl << "mul" << endl << "div" << endl
            << "sub" << endl << "exit" << endl;
        cin >> command;

        if(command == "exit")
            break;

        cout << "Enter first argument: ";
        cin >> a;
        cout << "Enter second argument: ";
        cin >> b;

        if(command == "add")
            cout << add(a,b) << endl << endl;
        else if(command == "sub")
            cout << sub(a,b) << endl << endl;
        else if(command == "mul")
            cout << mul(a,b) << endl << endl;
        else if(command == "div")
            cout << div(a,b) << endl << endl;
    }
}

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
double div(int x, int y) { return x / (double)y; }
int mul(int x, int y) { return x * y; }
