#include <iostream>

using namespace std;

int main(void)
{
    cout << "f(x) : f(x) = x*x" << endl;
    for(int i = 1; i <= 20; i++)
        cout << "f(" << i << ")" << " = " << i*i << endl;
    return 0;
}
