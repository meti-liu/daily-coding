#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 生成next数组
void GetNext(const string& t, vector<int>& next) {
    int j = 0, k = -1;
    next[0] = -1;
    int m = t.length();
    while (j < m - 1) {
        if (k == -1 || t[k] == t[j]) {  // 修正条件判断
            j++;
            k++;
            next[j] = k;
        }
        else {
            k = next[k];
        }
    }
}

// KMP算法统计子串出现次数
int KMPCount(const string& s, const string& t) {
    int n = s.length(), m = t.length();
    if (m == 0) return 0;  // 如果模式串为空，返回0
    vector<int> next(m, -1);  // 使用vector管理内存
    GetNext(t, next);
    int count = 0;
    int i = 0, j = 0;
    while (i < n) {
        if (j == -1 || s[i] == t[j]) {
            i++;
            j++;
            if (j == m) {  // 找到一个匹配
                count++;
                j = next[j - 1] + 1;  // 继续寻找下一个匹配
            }
        }
        else {
            j = next[j];
        }
    }
    return count;
}

int main() {
    string t, S;
    // 读取子串t和主串S
    cin >> t;
    cin >> S;
    
    // 计算并输出子串t在主串S中出现的次数
    int result = KMPCount(S, t);
    cout << result << endl;
    
    return 0;
}
