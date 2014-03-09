#include <iostream>
#include <string>
#include <climits>

using namespace std;

string num_to_text(int number);
string three_digit_chunk(int number, int level);
string two_digit_chunk(int number);
string lt_twenty(int number);

int main(void)
{
    int number;

    cout << "Which number would you like to pronounce?" << endl;
    cin >> number;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Your number was too high or too low. Try again." << endl;
        cin >> number;
    }
    
    string str_num = num_to_text(number);

    cout << str_num << endl;
    
    /*
     * print all the numbers from -999,999 to 999,999
     *
    for(int i = -999999; i < 999999; i++)
        cout << num_to_text(i) << endl;
    *
    */
}

string num_to_text(int number)
{
    string sign;
    string str_num;

    // if num less than zero, add negative, then process
    // as a normal number
    if(number < 0)
    {
        sign = "negative ";
        number *= -1;
    }

    // hardcode in zero case
    if(number == 0)
    {
        str_num = "zero";
    }
    // process as two digit chunk if only two digits
    else if(number < 100)
    {
        str_num = two_digit_chunk(number);
    }
    else
    {
        /*
         * loop through the number until we subtract
         * it's component places down to zero
         */
        for(int i = 0; number > 0; i++)
        {
            // remainder is what we have in hundreds place
            int hundreds = number % 1000;
            string temp = str_num;
            str_num = three_digit_chunk(hundreds, i);
            str_num += temp;
            number -= hundreds;
            number /= 1000;
        }
    }

    return (sign + str_num);   
}

string three_digit_chunk(int number, int level)
{
    string str_num = "";

    // if level > 3, number is too big
    if (number < 0 || level < 0 || level > 3)
        return "ERROR";

    // perform integer division to get the hundreds place
    int hun_place = number / 100;   
    int ten_place = number % 100;

    // if both are zero, this part won't be pronounced
    if(hun_place != 0 || ten_place != 0)
    {
        string hundreds = lt_twenty(hun_place);
        string tens = two_digit_chunk(ten_place);
        string magnitude;

        if(level == 0)
            magnitude = "";              
        else if(level == 1)   
            magnitude = " thousand ";
        else if(level == 2)
            magnitude = " million ";
        else if(level == 3)
            magnitude = " billion ";
        else
            magnitude = "ERROR";

        if(hun_place != 0)
        {
            str_num += hundreds;
            str_num += " hundred ";
        }
        str_num += tens;
        str_num += magnitude;
    }
    

    return str_num;
}

/**
 * prints the text of the digit in the tens
 * place, else prints ERROR!!! if number >= 100
 */
string two_digit_chunk(int number)
{
    // only process numbers under 100
    if(number < 0 || number >= 100)
        return "ERROR!!!";

    // give the integer division, i.e. the tens place
    int tens_place = number / 10;
    int ones_place = number - tens_place * 10;

    string computed_text = "";
    // otherwise, process the two digit num
    if(tens_place == 0)
    {
        computed_text += lt_twenty(number);
    }
    else if(tens_place == 1)
    {
        computed_text +=  lt_twenty(number);
    }
    else if(tens_place == 2)
    {
        computed_text += "twenty";
        computed_text += " ";
        computed_text += lt_twenty(ones_place);
    }
    else if(tens_place == 3)
    {
        computed_text += "thirty";
        computed_text += " ";
        computed_text += lt_twenty(ones_place);
    }
    else if(tens_place == 4)
    {
        computed_text += "forty";
        computed_text += " ";
        computed_text += lt_twenty(ones_place);
    }
    else if(tens_place == 5)
    {
        computed_text += "fifty";
        computed_text += " ";
        computed_text += lt_twenty(ones_place);
    }
    else if(tens_place == 6)
    {
        computed_text += "sixty";
        computed_text += " ";
        computed_text += lt_twenty(ones_place);
    }
    else if(tens_place == 7)
    {
        computed_text += "seventy";
        computed_text += " ";
        computed_text += lt_twenty(ones_place);
    }
    else if(tens_place == 8)
    {
        computed_text += "eighty";
        computed_text += " ";
        computed_text += lt_twenty(ones_place);
    }
    else if(tens_place == 9)
    {
        computed_text += "ninety";
        computed_text += " ";
        computed_text += lt_twenty(ones_place);
    }
    else 
    {
        computed_text += "ERROR!!!";
    }

    return computed_text;
}

/**
 * prints the text for a number less than 20, 
 * but if number >= 20, prints ERROR!!!, or if
 * number == 0, returns "" (blank string)
 */
string lt_twenty(int number)
{
    if(number == 0) return "";
    else if(number == 1) return "one";
    else if(number == 2) return "two";
    else if(number == 3) return "three";
    else if(number == 4) return "four";
    else if(number == 5) return "five";
    else if(number == 6) return "six";
    else if(number == 7) return "seven";
    else if(number == 8) return "eight";
    else if(number == 9) return "nine";
    else if(number == 10) return "ten";
    else if(number == 11) return "eleven";
    else if(number == 12) return "twelve";
    else if(number == 13) return "thirteen";
    else if(number == 14) return "fourteen";
    else if(number == 15) return "fifteen";
    else if(number == 16) return "sixteen";
    else if(number == 17) return "seventeen";
    else if(number == 18) return "eightteen";
    else if(number == 19) return "nineteen";   
    else return "ERROR!!!";
}
