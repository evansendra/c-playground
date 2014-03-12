/*
 * insertion_sort.cpp
 *
 * Evan Sendra
 *
 * detects if a constant sized array is or isn't sorted, sorts
 * it if needed, and finally prints out the sorted array
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE 3 

void sort(int arr[], int size);
bool is_sorted(int arr[], int size);

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
    
    if(!is_sorted(arr, SIZE))
        sort(arr, SIZE);

    for(int i = 0; i < SIZE; i++)
        cout << arr[i] << endl;
}

void sort(int arr[], int size)
{
    cout << endl << "SORTING..." << endl;
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

bool is_sorted(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
        if(arr[i] > arr[i + 1])
            return false;

    return true;
}
