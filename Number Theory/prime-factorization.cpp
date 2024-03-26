/*
***Prime Factorization***
Time Complexity: O(sqrt(n))
Auxiliary Space: O(1)
*/
#include <iostream>
using namespace std;

// Print all prime factors
// of a given number n .
void primeFactor(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        cout << 2 << ' ';
        n /= 2;
    }

    // n must be odd at this point. So we can skip 
    // one element (Note i += 2)
    for (int i = 3; i * i <= n; i += 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << ' ';
            n /= i;
        }
    }

    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        cout << n << ' ';
}

int main()
{
    int n;
    cin >> n;
    primeFactor(n);
}
