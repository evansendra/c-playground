#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void print3DMultTable(int length, int width, int height);

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        cout << "usage: ./3d-mult-tables <# of tables> <# of rows> <# of columns>" << endl;
        return 1;
    }
    
    int height = atoi( argv[ 1 ] );
    int length = atoi( argv[ 2 ] );
    int width = atoi( argv[ 3 ] );

    print3DMultTable(length, width, height);
}

void print3DMultTable(int length, int width, int height)
{
    int ***p_p_p_mult_tables;
    p_p_p_mult_tables = new int**[ height ];

    for(int i = 0; i < height; i++)
        p_p_p_mult_tables[ i ] = new int*[ length ];

    for(int i = 0; i < height; i++)
        for(int j = 0; j < length; j++)
            p_p_p_mult_tables[ i ][ j ] = new int[ width ];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < length; j++)
        {
            for(int k = 0; k < width; k++)
            {
                p_p_p_mult_tables[ i ][ j ][ k ] = (j + 1) * (k + 1);
                cout << p_p_p_mult_tables[ i ][ j ][ k ] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // delete the third dimension
    for(int i = 0; i < height; i++)
        for(int j = 0; j < length ; j++)
            delete[] p_p_p_mult_tables[ i ][ j ];

    // delete the second dimension
    for(int i = 0; i < height; i++)
        delete[] p_p_p_mult_tables[ i ];

    // delete the first dimension
    delete[] p_p_p_mult_tables;

    // can't use this ref for anything meaningful
    p_p_p_mult_tables = NULL;
}
