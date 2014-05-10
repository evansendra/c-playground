#include <iostream>
using namespace std;

struct Foo
{
    int bar;
    Foo *p_foo;
};

void change_bar (Foo *f)
{
    // can't do the below line here if ptr is const
    // f->bar *= 5;

    // can never do this
    f = new Foo;
    f->bar = 50;
}

int main (void)
{
    Foo f;
    f.bar = 0;
    change_bar(&f);
    cout << f.bar << endl;

    return 0;
}
