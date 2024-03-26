/*
***Selection Sort***
Time Complexity: O(n^2)
Auxiliary Space: O(1)
*/
#include <iostream>
using namespace std;

// Implementation of Selection Sort
void selectionSort(int arr[], int n)
{
    
}

int main()
{
    cout << "Enter size of the array: ";
    int n;
    cin >> n;

    cout << "Enter elements of the array: ";
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}
