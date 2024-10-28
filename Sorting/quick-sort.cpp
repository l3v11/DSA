/*
***Quick Sort***
Time Complexity: O(n logn)
Auxiliary Space: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array into two halves around a pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // Select the pivot element (first element in this case)
    int left = low; // Initialize left pointer
    int right = high; // Initialize right pointer

    // Continue until left pointer
    // is less than right pointer
    while (left < right) {
        // Move the left pointer to the right until
        // it finds an element greater than the pivot
        while (arr[left] <= pivot and left < high)
            left++;

        // Move the right pointer to the left until
        // it finds an element less than or equal to the pivot
        while (arr[right] > pivot and right >= low + 1)
            right--;

        // Swap elements at left and right pointers
        // if they haven't crossed each other
        if (left < right)
            swap(arr[left], arr[right]);
    }

    swap(arr[low], arr[right]); // Swap the pivot element with the element at the right pointer
    return right; // Return the index of the pivot element after partitioning
}

// Function for Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return; // base case
    int pi = partition(arr, low, high); // Partition the array and get the index of the pivot
    quickSort(arr, low, pi - 1); // sort the left half (less than the pivot)
    quickSort(arr, pi + 1, high); // sort the right half (greater than the pivot)
}

int main() {
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    cout << "Enter the elements of the array: ";
    vector<int> arr;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	arr.push_back(x);
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (auto num : arr)
        cout << num << ' ';
    cout << '\n';
}
