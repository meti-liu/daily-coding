#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ifstream ifs("in.txt");
    ofstream ofs("out.txt");


    string input;
    getline(ifs, input);

    // 统计字符频率
    vector<int> freq(256, 0); // ASCII范围内字符频率数组
    for (char c : input) freq[c]++;//自动将字符c转为ASCII数

    // 将字符按照频率和ASCII顺序存储
    vector<char> chars;
    for (int i = 0; i < 256; i++) 
    {
        if (freq[i] > 0) chars.push_back((char)i);//以数字形式存回chars中
    }


    for (int i = 0; i < chars.size() - 1; i++) 
    {
        for (int j = i + 1; j < chars.size(); j++) 
        {
            // 比较频率和ASCII值
            if (freq[chars[j]] > freq[chars[i]] || (freq[chars[j]] == freq[chars[i]] && chars[j] < chars[i])) {
                swap(chars[i], chars[j]); // 交换字符的位置
            }
        }
    }

    // 构造结果字符串
    string result;
    for (char c : chars) 
    result += string(freq[c], c); // 添加freq[c]个字符c


    cout<< result;

    return 0;
}
