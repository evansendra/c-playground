#include <iostream>

using namespace std;

int main(void)
{
    // sing 12 verses
    for(int i = 1; i <= 12; i++)
    {
        string ordinal_num;
        switch(i)
        {
            case 1:
                ordinal_num = "First";
                break;
            case 2:
                ordinal_num = "Second";
                break;
            case 3:
                ordinal_num = "Third";
                break;
            case 4:
                ordinal_num = "Fourth";
                break;
            case 5:
                ordinal_num = "Fifth";
                break;
            case 6:
                ordinal_num = "Sixth";
                break;
            case 7:
                ordinal_num = "Seventh";
                break;
            case 8:
                ordinal_num = "Eighth";
                break;
            case 9:
                ordinal_num = "Ninth";
                break;
            case 10:
                ordinal_num = "Tenth";
                break;
            case 11:
                ordinal_num = "Eleventh";
                break;
            case 12:
                ordinal_num = "Twelfth";
                break;
            default:
                ordinal_num = "ERROR";
                break;
        }

        cout << "On the " << ordinal_num << " day of Christmas, my true love gave to me"
            << endl;

        string gift;
        switch(i)
        {
            case 12:
                cout << "twelve drummers drumming" << endl;
            case 11:
                cout << "eleven pipers piping" << endl;
            case 10:
                cout << "ten lords-a-leaping" << endl;
            case 9:
                cout << "nine ladies dancing" << endl;
            case 8:
                cout << "eight maids-a-milking" << endl;
            case 7:
                cout << "seven swans-a-swimming" << endl;
            case 6:
                cout << "six geese-a-laying" << endl;
            case 5:
                cout << "FIVE GOOOOOOOOLD RINGS" << endl;
            case 4:
                cout << "four calling birds" << endl;
            case 3:
                cout << "three french hens" << endl;
            case 2:
                cout << "two turtle doves" << endl;
            case 1:
                if(i != 1)
                    cout << "and ";
                cout << "a partridge in a pear tree" << endl;
                break;
            default:
                cout << "ERROR";
                break;
        }
    
        // add an extra break line
        cout << endl;
    }
}
