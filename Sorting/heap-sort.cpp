/*
***Insertion Sort***
Time Complexity: O(n logn)
Auxiliary Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void heapSort(vector<int> &v) {
    // Convert vector to Max Heap
    make_heap(v.begin(), v.end());

    // Sort Max Heap
    sort_heap(v.begin(), v.end());
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

	heapSort(arr);

    cout << "Sorted array: ";
    for (auto num : arr)
        cout << num << ' ';
    cout << '\n';
}
