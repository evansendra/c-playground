#include <iostream>

using namespace std;

// prototype for squaring function
int f(int n);

int main(void)
{
    for(int i = 1; i <= 10; i++)
        cout << f(i) << endl;   
}

int f(int n)
{
    return n*n;
}
