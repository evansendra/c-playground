#include <iostream>
#include <string>
#include <cmath>

// maximum ascii bar chart height
#define BAR_HEIGHT 20

using namespace std;

int main(void)
{
    // prompt user to give poll questions and answers
    string question, ans1, ans2, ans3;
    cout << "== Poll Maker ==" << endl;
    cout << "question: ";
    getline(cin, question, '\n');

    cout << "answer 1: ";
    getline(cin, ans1, '\n');
    cout << "answer 2: ";
    getline(cin, ans2, '\n');
    cout << "answer 3: ";
    getline(cin, ans3, '\n');

    cout << endl;

    // prompt user to respond to poll as many times as desired
    int response;
    int one = 0;
    int two = 0;
    int three = 0;
    do
    {
        cout << question << endl << "1: " << ans1 << endl 
            << "2: " << ans2 << endl << "3: " << ans3 << endl;
        cout << "Response (0 to exit): ";
        cin >> response;
        cout << endl;
        if(response == 1)
            one++;
        else if(response == 2)
            two++;
        else if(response == 3)
            three++;
    }
    while(response != 0);

    // give some padding
    cout << endl << endl << "=== Summary ===" << endl << endl;

    // cout << endl << "Summary:" << endl << ans1 << ": " << one << endl
    //     << ans2 << ": " << two << endl << ans3 << ": " << three << endl;
    
    // scale responses to bar height
    double max = fmax(one, fmax(two, three));
    int scaled_one = (one / max) * BAR_HEIGHT;
    int scaled_two = (two / max) * BAR_HEIGHT;
    int scaled_three = (three / max) * BAR_HEIGHT;


    // summarize poll results to user thru ascii bar chart
    for(int height = BAR_HEIGHT; height > 0; height--)
    {
       if(scaled_one > height)
           cout << "  ##";
       else
           cout << "    ";

       cout << "       ";

       if(scaled_two > height)
           cout << "##";
       else
           cout << "  ";

       cout << "        ";

       if(scaled_three > height)
           cout << "##";
       else
           cout << "  ";

       cout << "     " << endl;
    }

    cout << endl;
    cout << "= 1 =" << "     " << "= 2 =" << "     " << "= 3 =" << "     " << endl;
}
