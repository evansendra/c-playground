/**
 * illustrates getting heap memory for the program 
 * by creating a resizable array to which the user can
 * add new elements forever (okay, not forever, but for
 * a long time)
 *
 * eas
 */

#include <iostream>

using namespace std;

int* growArray(int *array, int *size);
void printArray(int *array, int elements_set, int size);

int main(void)
{
    int cur_element = 0;
    int size = 10;
    int *p_elements = new int[ size ];

    int input;
    cout << "Please enter a number: ";
    cin >> input;

    do
    {
        // add the element to the array, resizing if necessary
        if(size == cur_element + 1)
        {
            // resize the array
            p_elements = growArray(p_elements, &size);
        }
        
        // put the input in the current slot, and increase
        // this slot for the next iteration
        p_elements[ cur_element++ ] = input;
        printArray(p_elements, cur_element, size);

        cout << "Please enter a number (0 for exit): ";
        cin >> input;
    }
    while(input != 0);

    delete[] p_elements;
    p_elements = NULL;
}

void printArray(int *array, int elements_set, int size)
{
    cout << "Elements set: " << elements_set << endl;
    cout << "Total size: " << size << endl;
    for(int i = 0; i < elements_set; i++)
        cout << "array[ " << i << " ] = " << array[i] << endl;
}

int* growArray(int *array, int *size)
{
    int old_size = *size;
    *size *= 2;
    int *new_arr = new int[ *size ];
    for(int i = 0; i < old_size; i++)
        new_arr[i] = array[i];
    delete[] array;
    array = NULL;
    return new_arr;
}
