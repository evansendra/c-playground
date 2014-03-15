#include <iostream>

#define HEIGHT 5
#define WIDTH 3

using namespace std;

void printTwoDArray(int arr[][ WIDTH ])
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


int main(void)
{
    int k = 0;
    int array[HEIGHT][WIDTH];
    int *p_array = array[ 0 ];

    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            array[i][j] = k++;

    printTwoDArray(array);


    cout << endl << "array[1][2] = " << array[1][2] << endl;

    // cout << endl << "array[1][2] = " << *(*(array + 1) + 2) << endl;
    cout << endl << "array[1][2] = " << *(p_array + 1 * WIDTH + 2) << endl;
}
