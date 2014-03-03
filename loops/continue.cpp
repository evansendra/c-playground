#include <iostream>

using namespace std;

int main(void)
{
    int i = 0;
    while(true)
    {
        i++;
        if(i == 10)
            continue;
        else if(i == 12)
            break;

        cout << i << endl;
    }
}
