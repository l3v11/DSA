// inserting an element in an array
#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int arr[size + 1] = {1, 2, 4, 5, 6};  // Extra space for the new element

    int element = 3;
    int index = 2;

    // Shift elements to the right
    for (int i = size - 1; i >= index; i--)
        arr[i + 1] = arr[i];
    
    // Insert new element
    arr[index] = element;
    
    // Display the array with the new element inserted
    for (int i = 0; i < size + 1; i++)
        cout << arr[i] << " ";

    return 0;
}
