#include <iostream>
#include <algorithm>  // 用于 std::max
using namespace std;

const int MAX_N = 1000;  // 物品数量最大为 1000
const int MAX_V = 1000;  // 背包容量最大为 1000

int dp[MAX_N + 1][MAX_V + 1];  // 二维 DP 数组
int w[MAX_N + 1];  // 物品的体积
int v[MAX_N + 1];  // 物品的价值

int main() {
    int n, V;
    cin >> n >> V;  // 输入物品数量 n 和背包容量 V

    // 输入每个物品的体积和价值
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    // 初始化 dp 数组，表示没有物品时任何容量的背包的最大价值为 0
    for (int j = 0; j <= V; j++) {
        dp[0][j] = 0;
    }

    // 动态规划计算最大价值
    for (int i = 1; i <= n; i++) {  // 遍历所有物品
        for (int j = V; j >= w[i]; j--) {  // 遍历背包容量从大到小
            // 如果可以放入物品 i，更新 dp 数组
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
        }
    }

    // 输出最大价值
    cout << dp[n][V] << endl;
    return 0;
}
