#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int>& v, int target) {
    int s = 0;
    int e = v.size() - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2; // To avoid overflow
        if (v[mid] == target) {
            return mid;
        } else if (v[mid] > target) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 8};
    int target = 5;

    int res = BinarySearch(v, target);

    if (res != -1) {
        cout << "Element found at index: " << res << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}
