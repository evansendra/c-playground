#include <iostream>
#include <fstream>

using namespace std;

int main (void)
{
    ifstream read_file("foo.txt");
    // check if file is open
    if (!read_file.is_open())
    {
        cout << "couldn't open file!" << endl;
        return 0;
    }

    // attempt to read in a number
    int num;
    if (read_file >> num)
        cout << "Number is " << num << endl;
    else
        cout << "Bad input file format...expected a number" << endl;
}
