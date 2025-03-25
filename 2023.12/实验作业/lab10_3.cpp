#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a = {3, 1, 4, 2, 5};
    int n;
    cout << "请输入需要查找的数: ";
    cin >> n; // 需要查找的数

    auto p = find(a.begin(), a.end(), n);

    if (p != a.end()) {
        // 如果找到元素
        int index = distance(a.begin(), p);
        cout << "元素的索引: " << index << endl;
    } else {
        // 如果没有找到元素
        cout << "数组中没有该元素" << endl;
    }

    return 0;
}
