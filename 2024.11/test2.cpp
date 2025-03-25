#include <iostream>
#include <string>
#include <sstream>  // 用于处理输入流
using namespace std;

const int MAXV = 1000;

struct MGraph {
    int numV, numE;
    char Verticles[MAXV];
    int edge[MAXV][MAXV];

    // 构造函数
    MGraph(string v, string e) {
        numV = 0;
        numE = 0;

        // 处理顶点输入
        int i = 0;
        while (i < v.length()) {
            if (v[i] >= 'a' && v[i] <= 'z') {
                Verticles[numV++] = v[i];
            }
            i++;
        }

        // 初始化邻接矩阵
        for (int i = 0; i < numV; i++) {
            for (int j = 0; j < numV; j++) {
                edge[i][j] = 0;  // 初始时没有边
            }
        }

        // 处理边的输入
        i = 0;
        char u, w;
        while (i < e.length()) {
            if (e[i] == '(') {
                u = e[i + 1];
                w = e[i + 3];
                edge[Index(u)][Index(w)] = 1;
                numE++;
                i += 5; // 跳过 "(u,v)" 的格式
            } else {
                i++;
            }
        }
    }

    // 获取顶点的索引
    int Index(char find) {
        for (int i = 0; i < numV; i++) {
            if (find == Verticles[i]) return i;
        }
        return -1;  // 如果找不到，返回 -1
    }
};

// 打印 K 顶点并返回个数
int PrintV(MGraph G) {
    int cnt = 0;
    int out[MAXV], in[MAXV];
    for (int i = 0; i < G.numV; i++) {
        out[i] = in[i] = 0;  // 初始化出度和入度
    }

    // 计算出度和入度
    for (int i = 0; i < G.numV; i++) {
        for (int j = 0; j < G.numV; j++) {
            if (G.edge[i][j] == 1) {
                out[i]++;
                in[j]++;
            }
        }
    }

    cout << "K vertices: ";
    // 输出 K 顶点
    for (int i = 0; i < G.numV; i++) {
        if (out[i] > in[i]) {
            cout << G.Verticles[i] << " ";  // 只有出度大于入度的顶点才是 K 顶点
            cnt++;
        }
    }
    cout << endl;
    cout << "Number of K vertices: " << cnt << endl;
    return cnt;
}

int main() {
    string v, e;
    
    // 输入顶点和边的字符串
    cout << "Enter vertices (e.g., {a,b,c}): ";
    getline(cin, v);  // 输入顶点
    cout << "Enter edges (e.g., {(a,b),(b,c)}): ";
    getline(cin, e);  // 输入边

    // 检查输入格式
    if (v.empty() || e.empty() || v[0] != '{' || v[v.length() - 1] != '}' || e[0] != '{' || e[e.length() - 1] != '}') {
        cout << "Input format error! Please use the correct format." << endl;
        return 1;
    }

    // 处理输入格式，去掉花括号和圆括号
    v = v.substr(1, v.length() - 2);  // 去掉花括号 { }
    e = e.substr(1, e.length() - 2);  // 去掉圆括号 ( )

    MGraph G(v, e);
    PrintV(G);

    return 0;
}
