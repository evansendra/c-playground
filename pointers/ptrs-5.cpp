#include <iostream>

using namespace std;

int mult_and_add(int a, int b, int *product);

int main(void)
{
    int x, y, product;
    cout << "Provide two integers por favor." << endl;
    cin >> x;
    cin >> y;
    int sum = mult_and_add(x, y, &product);

    cout << "x + y = " << sum << " and x * y = " << product << endl;
}

int mult_and_add(int a, int b, int *product)
{
    if(product != NULL)
        *product = a * b;

    return a + b;   
}
