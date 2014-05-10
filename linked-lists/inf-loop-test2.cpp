struct Foo
{
    int a;
    int b;
    Foo *f;
};

int main (void)
{
    // infinite loop here, doesn't compile
    Foo foo;
    foo.a = 5;
    foo.b = 3;
    foo.a *= foo.a + foo.b;
    return 0;
}
