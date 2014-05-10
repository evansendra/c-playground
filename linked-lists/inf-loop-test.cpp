struct Foo
{
    int a;
    int b;
    Foo f;
};

int main (void)
{
    // infinite loop here, doesn't compile
    Foo foo;
    return 0;
}
