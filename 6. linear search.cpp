// linear search
#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;
    int index = -1;  // Default value if element is not found

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            index = i;
            break;  // Exit loop once the target is found
        }
    }

    if (index != -1)
        cout << "Element found at index " << index << '\n';
    else
        cout << "Element not found\n";

    return 0;
}
