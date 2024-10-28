/*
***Euclidean Algorithm***
Time Complexity: O(log(min(a,b)))
Auxiliary Space: O(log(min(a,b)))
*/
#include <iostream>
using namespace std;

// Function to compute the Greatest Common Divisor (GCD) of two numbers
int gcd (int a, int b) {
    // Base case: when b is 0, the GCD is a
    if (b == 0)
        return a;
    else
        return gcd (b, a % b); // Recursive case: GCD of b and the remainder of a divided by b
}

// Function to compute the Least Common Multiple (LCM) of two numbers
int lcm (int a, int b) {
    return a / gcd(a, b) * b; // To prevent overflow, we first divide a by GCD(a, b) and then multiply by b
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << ' ' << lcm(a, b);
}
