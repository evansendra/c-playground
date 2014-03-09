#include <iostream>

#define ARR_SIZE 5

using namespace std;

int sum(int array[], int size);

int main(void)
{
    int foo[ARR_SIZE];   
    for(int i = 0; i < ARR_SIZE; i++)
        cin >> foo[i];
    cout << sum(foo, ARR_SIZE) << endl;
}

int sum(int array[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += array[i];
    return sum;
}
