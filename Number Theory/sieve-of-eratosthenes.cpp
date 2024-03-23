/*
***Sieve of Eratosthenes***
Time Complexity: O(n log(log n))
Auxiliary Space: O(n)
*/
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    /*
    According to the algorithm we will mark all
    the numbers which are divisible by 'i' and are
    greater than or equal to the square of it. 
    */
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i]) // is 'i' true?
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    /*
    n = 30
    i = 2, j = 4, 6, 8, 10, ...., 30
    i = 3, j = 9, 12, 15, 18, ...., 30
    i = 4, false
    i = 5, j = 25, 30

    As 5*5 < 30 and 6*6 > 30
    So imax = 5
    */

    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            cout << i << ' ';
    cout << '\n';
}

int main()
{
    int n;
    cin >> n;
    sieve(n);
}
