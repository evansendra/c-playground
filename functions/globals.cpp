#include <iostream>

using namespace std;

/*
 * wouldn't have access up here
void inc()
{
    count++;
}
*/

int count = 0;

void fun()
{
    count++;
}

int main(void)
{
    fun();
    fun();
    fun();
    cout << "Count: " << count << endl;    
}
