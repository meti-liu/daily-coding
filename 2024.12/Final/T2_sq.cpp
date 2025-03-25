#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    node() {};
    node(int idx,char ch) {
        index = idx;
        c = ch;
    }
    int index;
    char c;
};
int main() {
    string x;
    char ch;
    cin >> x >> ch;
    int index = -1;

    for (int i = 0;i < x.length();i++) {
        if (x[i] == ch) {
            index = i;
        }
    }
    queue<node> q;
    q.push(node(index,x[index]));
    while (!q.empty()) {
        int idx = q.front().index;
        char ch = q.front().c;
        q.pop();
        if (ch != '#') {
            cout << ch << " ";


            if (2 * idx + 1 < x.length()) {
                q.push(node(2 * idx + 1, x[2 * idx + 1]));
            }
            if (2 * idx + 2 < x.length()) {
                q.push(node(2 * idx + 2, x[2 * idx + 2]));
            }
        }
    }
    return 0;
}