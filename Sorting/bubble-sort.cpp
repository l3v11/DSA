/*
***Bubble Sort***
Time Complexity: O(n^2)
Auxiliary Space: O(1)
*/
#include <iostream>
using namespace std;

// Implementation of Bubble Sort
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            /*
            '>' for ascending order
            '<' for descending order
            */
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }
        /*
        If no two elements were swapped
        by inner loop, then break
        */
        if (!swapped)
            break;
    }
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

    bubble_sort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}