#include <iostream>

using namespace std;

int main(void)
{
    int height;
    cout << "What's the height of the board? ";
    cin >> height;

    int width;
    cout << "What's the width of the board? ";
    cin >> width;

    int **p_p_board;
    p_p_board = new int*[ width ];
    for(int i = 0; i < width; i++)
        p_p_board[ i ] = new int[ height ];

    int k = 10;
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            p_p_board[ i ][ j ] = k++;
            cout << p_p_board[ i ][ j ] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < width; i++)
        delete[] p_p_board[ i ];

    delete[] p_p_board;
}
