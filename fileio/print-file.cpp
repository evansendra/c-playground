#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    ifstream in_file(argv[ 1 ]);
    if (!in_file.is_open())
    {
        cout << "Error opening " << argv[1] << endl;
        return 1;
    }

    char c;
    while (in_file.get(c))
    {
        cout << c;
    }
    return 0;
}
