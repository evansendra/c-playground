#include <iostream>

using namespace std;

int main(void)
{
    cout << "\033[1;32m" << "test 1 working :)" <<  "\033[0m\n";
    cout << "\033[1;32m" << "test 2 working :)" <<  "\033[0m\n";
    cout << "\033[1;32m" << "test 3 working :)" <<  "\033[0m\n";
    cout << "\033[1;31m" << "test 4 failed :(" << "\033[0m\n";
}
