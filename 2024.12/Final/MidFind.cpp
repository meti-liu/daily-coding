#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid; // 找到返回索引
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // 未找到返回 -1
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int key = 5;
    int index = binarySearch(arr, key);
    if (index != -1) cout << "Found at index: " << index << endl;
    else cout << "Not found" << endl;
    return 0;
}
