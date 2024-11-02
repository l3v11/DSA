// binary search
#include <iostream>
#include <vector>

using namespace std;

int bin_srch(int a, int b, vector<int> &v, int target) {
    int lo = a, hi = b, mid;
    
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        
        if (v[mid] == target)
            return mid + 1;  // Adjusted for 1-based index
        else if (v[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    
    return -1;  // Target not found
}

int main() {
    vector<int> v = {1, 2, 5, 7, 7, 9, 9};
    int target = 7;
    int ans = bin_srch(0, v.size() - 1, v, target);

    if (ans != -1)
        cout << "Target element found at index: " << ans << endl;
    else
        cout << "Element not found\n";

    return 0;
}
