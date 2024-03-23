/*
***Primality Test***
Time Complexity: O(sqrt(n))
Auxiliary Space: O(1)
*/
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return n >= 2;
}

int main()
{
    int n;
    cin >> n;

    if (isPrime(n))
        cout << "Prime\n";
    else
        cout << "Not Prime\n";
}
