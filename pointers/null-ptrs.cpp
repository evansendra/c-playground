#include <iostream>

using namespace std;

int main(void)
{
    int foo = 69;
    int *p_foo = NULL;   
    if(p_foo != NULL)
        cout << *p_foo;

    p_foo = &foo;
    if(p_foo != NULL)
        cout << "p_foo = " << p_foo << "; *p_foo = " << *p_foo << endl;
}
