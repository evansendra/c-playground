#include <iostream>

using namespace std;

void printAddresses(int length, int width);

int main(void)
{
    int l, w;
    cout << "length? ";
    cin >> l;
    cout << "width? ";
    cin >> w;

    printAddresses(l, w);
}

void printAddresses(int length, int width)
{
    int **p_p_arr;
    p_p_arr = new int*[ length ];

    for(int i = 0; i < length; i++)
        p_p_arr[ i ] = new int[ width ];

    for(int i = 0; i < length; i++)
    {
        cout << "Addresses of elements in array " << i << ": " << endl;
        for(int j = 0; j < width; j++)
            cout << &(p_p_arr[ i ][ j ]) << endl;
        cout << endl;
    }

    for(int i = 0; i < length; i++)
        delete[] p_p_arr[ i ];

    delete[] p_p_arr;
}
