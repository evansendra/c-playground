#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void print_mult_table(int width, int height);

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        cout << "usage: ./mult-table <rows> <columns>" << endl;
        return 1;
    }

    int width = atoi( argv[ 2 ] );
    int height = atoi( argv [ 1 ] );

    print_mult_table(width, height);
}

void print_mult_table(int width, int height)
{
    int **p_p_arr;
    p_p_arr = new int*[ height ];
    
    for(int i = 0; i < height; i++)
        p_p_arr[ i ] = new int[ width ];

    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            p_p_arr[ i ][ j ] = (i + 1) * (j + 1);

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            printf("%5d ", p_p_arr[ i ][ j ]);

        cout << endl;
    }
}
