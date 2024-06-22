/*
***Merge Sort***
Time Complexity: O(n logn)
Auxiliary Space: O(n)
*/
#include <iostream>
#include <vector>
using namespace std;

// Function for Merge Sort
void merge(vector<int> &arr, int low, int mid, int high) {
	vector<int> tmp;
	int left = low; // starting index of left half of arr
	int right = mid + 1; // starting index of right half of arr

	// storing elements in the tmp array in a sorted manner
	while (left <= mid and right <= high) {
		if (arr[left] <= arr[right])
			tmp.push_back(arr[left++]);
		else
			tmp.push_back(arr[right++]);
	}

	// if elements on the left half are still left
	while (left <= mid)
		tmp.push_back(arr[left++]);

	// if elements on the right half are still left
	while (right <= high)
		tmp.push_back(arr[right++]);

	// transfering all elements from tmp to arr
	for (int i = low; i <= high; i++)
		arr[i] = tmp[i - low];

	/*
	Q. Why doing tmp[i - low] instead of tmp[i]?

	The answer is very simple, the tmp array stores the merged
	array, so in tmp array, elements will be stored from 0th index
	to last index, so in order to get the arr[i] value, we will
	have to pick it up from the 0th index of tmp array, in order to
	get arr[i + 1] value, we have to pick it up from tmp[1],
	so hence we need to do i - low.

	To my observation, not putting i - low will cause the right
	half of the given array to go out of bound as tmp array is
	being created in every call.
	*/
}

void mergeSort(vector<int> &arr, int low, int high) {
	if (low >= high) return;

	int mid = low + (high - low) / 2;
	mergeSort(arr, low, mid); // left half
	mergeSort(arr, mid + 1, high); // right half
	merge(arr, low, mid, high); // merging sorted halves
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

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (auto num : arr)
        cout << num << ' ';
    cout << '\n';
}
