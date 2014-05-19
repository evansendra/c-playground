#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main ()
{
    ifstream infile("scores.txt");
    if (!infile.is_open())
    {
        cout << "Could not open the file!" << endl;
    }
    else
    {
        vector<int> scores;
        for (int i = 0; i < 10; ++i)
        {
            int tmp;
            infile >> tmp;
            scores.push_back(tmp);
        }

        for (auto itr = scores.begin();
            itr != scores.end();
            ++itr)
        {
            cout << *itr << endl;
        }
    }

    return 0;
}
