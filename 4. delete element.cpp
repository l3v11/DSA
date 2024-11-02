// deleting an element in an array
#include <iostream>
using namespace std;

int main() {
    int size = 6;
    int arr[size] = {1, 2, 3, 4, 5, 6};
    int index = 2;

    // Shift elements to the left to delete the element at the given index
    for (int i = index; i < size - 1; i++)
        arr[i] = arr[i + 1];
    
    // Set the last element to 0 to indicate it's "removed"
    arr[size - 1] = 0;

    // Display the array after deletion
    for (int i = 0; i < size; i++)  // use size - 1 to remove 0
        cout << arr[i] << " ";

    return 0;
}
