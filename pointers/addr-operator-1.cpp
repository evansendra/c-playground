#include <iostream>

using namespace std;

void swap(int& a, int& b);

int main(void)
{
    int foo = 5;
    int baz = 692;

    cout << "foo = " << foo << "; baz = " << baz << endl;
    swap(foo, baz);
    cout << "foo = " << foo << "; baz = " << baz << endl;
}

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
