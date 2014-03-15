#include <iostream>

using namespace std;

int main(void)
{
    int size = 50;
    int *foo = new int[ size ];   
    int *p_foo_1 = &foo[ 10 ];
    int *p_foo_2 = &foo[ 40 ];
    cout << "&foo[40] - &foo[10] = " << p_foo_2 - p_foo_1 << endl;
    delete[] foo;
}
