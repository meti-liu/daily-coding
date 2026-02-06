#include <iostream>
#include <vector>
using namespace std;

int main() {
    int s, n;
    cin >> s >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // 动态规划数组 dp[i] 表示和为 i 的组合数
    vector<int> dp(s + 1, 0);
    dp[0] = 1;  // 和为 0 的组合只有一种，即不选择任何数

    // 遍历每个数字
    for (int i = 0; i < n; i++) {
        for (int j = nums[i]; j <= s; j++) {
            dp[j] += dp[j - nums[i]];
        }
    }

    // 输出结果
    cout << dp[s] << endl;

    return 0;
}
