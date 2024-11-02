#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr = arr;

    // Input elements using the pointer
    for (int i = 0; i < size; i++)
        cin >> *(ptr + i);

    // Output elements using the pointer
    for (int i = 0; i < size; i++)
        cout << *(ptr + i) << " ";

    return 0;
}
