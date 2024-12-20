/*
***Insertion Sort***
Time Complexity: O(n^2)
Auxiliary Space: O(1)
*/
#include <iostream>
using namespace std;

// Function for Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int tmp = arr[i];
        int j = i - 1;
        /*
        Move elements of arr[0..i-1],
        that are greater than tmp, 
        to one position ahead of their
        current position
        */
        while(j >= 0 and arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

int main() {
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    cout << "Enter the elements of the array: ";
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}
