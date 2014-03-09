#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

#define FLIPS 1000

using namespace std;

int main(void)
{
    srand( time( NULL ) );
    int rand_max;
    int rand_min;
    
    /*
    cout << "What is the random range min? ";
    cin >> rand_min;

    cout << "What is the random range max? ";
    cin >> rand_max;
    */
    rand_min = 0;
    rand_max = 1;

    int heads_count;
    int tails_count;

    for(int i = 0; i < FLIPS; i++)
    {
        // returns random within range
        int flip = rand() % (rand_max - rand_min + 1) + rand_min;
        switch(flip)
        {
            case 0:
                cout << "Heads!" << endl;
                heads_count++;
                break;
            case 1:
                cout << "Tails!" << endl;
                tails_count++;
                break;
            default:
                cout << "Error occurred." << endl;
                exit(EXIT_FAILURE);
                break;
        }
        usleep(1e3);
    }
    
    cout << "Heads ratio: " << heads_count / (double)FLIPS << endl
        << "Tails ratio: " << tails_count / (double)FLIPS << endl;
}
