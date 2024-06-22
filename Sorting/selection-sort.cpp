/*
***Selection Sort***
Time Complexity: O(n^2)
Auxiliary Space: O(1)
*/
#include <iostream>
using namespace std;

// Function for Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        /*
        Find the minimum element in
        the unsorted array
        */
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            /*
            '<' for ascending order
            '>' for descending order
            */
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        /*
        Swap the found minimum element with
        the first element of the array
        */
        if (min_idx != i)
            swap(arr[i], arr[min_idx]);
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

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}
