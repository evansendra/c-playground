/**
 * prime_finder.c
 *
 * Evan Sendra
 *
 * finds all numbers from 1 to an upper limit whose prime 
 * factors, when added, sum to a prime number
 */

#include <iostream>
#include <cmath>

#define UPPER_LIMIT 150

int prime_factorize(int num);
bool is_prime(int num);

using namespace std;

/**
 * prints out all numbers from 1 to UPPER_LIMIT whose
 * sum of prime factors (non-distinct) are prime
 */
int main(void)
{
    for(int i = 2; i <= UPPER_LIMIT; i++)
    {
        int sum = prime_factorize(i);

        // if the sum of primes is itself prime, print it
        if(is_prime(sum))
            cout << i << endl;
    }
}

/**
 * finds the prime factors of a number and returns the sum
 * of these prime factors
 */
int prime_factorize(int num)
{
    int sum = 0;
    int lowest_prime = 0;
    
    // find the lowest prime number of the num in question
    for(int i = 2, r = ceil(sqrt(num)); i <= r && lowest_prime == 0; i++)
    {
        if(num % i == 0)
        {
            if(is_prime(i))
                lowest_prime = i;
        }
    }
    
    // add the lowest prime factor to the sum
    sum += lowest_prime;

    // if the lowest prime was zero, the number itself was prime
    if(lowest_prime == 0)
    {
        sum = num;
    }
    else
    {
        // in recursive case, multiplier isn't prime
        // in base case, it is
        int multiplier = (num / lowest_prime);

        if(is_prime(multiplier))
            sum += multiplier;
        else
            sum += prime_factorize(multiplier);
    }

    return sum;
}

/**
 * returns true if the number is prime, else false
 */
bool is_prime(int num)
{
    // 0 and 1 aren't primes
    if(num == 0 || num == 1)
        return false;

    // trial division it is!
    for(int i = 2, r = ceil(sqrt(num)); i <= r; i++)
        if(num % i == 0 && num != i)
            return false;

    // if we get here, it's prime
    return true;
}
