#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    ofstream outfile("scores.txt");
    if (!outfile.is_open())
    {
        cout << "Could not open the file!" << endl;
    }
    else
    {
        for (int i = 1; i <= 100; ++i)
        {
            outfile << (100 * i) << endl;
        }
    }

    return 0;
}
