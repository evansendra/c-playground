/**
 * prime_finder.c
 *
 * Evan Sendra
 *
 * finds all numbers from 1 to 1000 whose prime factors, when added, 
 * sum to a prime number
 */

#include <iostream>
#include <cmath>

#define UPPER_LIMIT 1000

bool is_factor(int num, int component);
bool is_prime(int num);

using namespace std;

int main(void)
{
    for(int i = 1; i <= UPPER_LIMIT; i++)
    {
        int sum = 0;
        for(int j = 2; j <= i; j++)
        {
            if(is_factor(i, j) && is_prime(j))
            {
                sum += j;
            }
        }

        // if the sum of primes is itself prime, print it
        if(is_prime(sum))
            cout << i << endl;
    }
}

/**
 * returns true if component is a factor of num
 */
bool is_factor(int num, int component)
{
    return (component < num) && (num % component == 0);
}

/**
 * returns true if num is divisible by nothing but between
 * 2 and its sqrt
 */
bool is_prime(int num)
{
    for(int i = 2; i < (int)sqrt((double)num); i++)
        if(num % i == 0) return false;
    return true;
}
