#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE 10

void sort(int arr[], int size);

int main(void)
{
    srand( time( NULL ) );
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++)   
    {
        arr[i] = rand() % (2000 - 0 + 1) + 0;
        cout << arr[i] << endl;
    }

    cout << endl;
    
    sort(arr, SIZE);
    for(int i = 0; i < SIZE; i++)
        cout << arr[i] << endl;
}

void sort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int min_index = i;
        for(int j = i; j < size; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        // swap this element with previous "min" element if it's not
        // the element we started with
        if(min_index != i)
        {
            int tmp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = tmp;
        }
    }
}
