#include <iostream>

using namespace std;

struct fooStruct
{
    int bar[ 100 ];
};

void initStruct(fooStruct& foo);

int main(void)
{
    fooStruct baz;
    cout << baz.bar[ 0 ] << endl;
    initStruct(baz);
    cout << baz.bar[ 0 ] << endl;
}

void initStruct(fooStruct& foo)
{
    foo.bar[ 0 ] = 2000;
}
