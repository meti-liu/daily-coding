#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n; 
    cin.ignore(); // 忽略读取 n 后的换行符

    // 用 vector 存储 n 个队列，队列编号从 1 开始
    vector<queue<string>> q(n+1);

    // 依次读取 n 行，每行表示一个队列初始的顾客顺序
    for (int i = 1; i <= n; i++)
    {
        string line;
        getline(cin, line);  // 读取整行输入
        istringstream iss(line);  // 利用 istringstream 分解字符串
        string name;
        while (iss >> name) {
            q[i].push(name);
        }
    }

    // 读取一行空行，将其丢弃
    string blank;
    getline(cin, blank);

    // 处理事件
    queue<string> Leave;  // 用来存储离队顾客的顺序
    string action;
    while (cin >> action)
    {
        if (action == "ENTERS")
        {
            string newName;
            int num;
            cin >> newName >> num;
            if (num >= 1 && num <= n)
                q[num].push(newName);
        }
        else if (action == "LEAVES")
        {
            int num;
            cin >> num;
            if (num >= 1 && num <= n && !q[num].empty())
            {
                string l = q[num].front();
                Leave.push(l);
                q[num].pop();
            }
        }
    }

    // 输出离开的顾客姓名
    while (!Leave.empty())
    {
        cout << Leave.front() << endl;
        Leave.pop();
    }

    // 输出每个队列的最终内容
    for (int i = 1; i <= n; i++)
    {
        cout << "q" << i << ":";
        while (!q[i].empty())
        {
            cout << q[i].front() << " ";
            q[i].pop();
        }
        cout << endl;
    }
    
    return 0;
}
