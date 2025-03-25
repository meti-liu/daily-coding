#include<iostream>
#include<string>
using namespace std;

const int MAXV = 100;

struct MGraph {
    int numV, numE;
    char Verticles[MAXV];
    int edge[MAXV][MAXV];

    MGraph(string v, string e) {
        numV = 0;
        numE = 0;

        // 初始化顶点
        int i = 0;
        while (i < v.length()) {
            if (v[i] <= 'z' && v[i] >= 'a') {
                Verticles[numV++] = v[i];  // 将字符添加到 Verticles 数组
            }
            i++;
        }

        // 初始化边
        for (int i = 0; i < numV; i++) {
            for (int j = 0; j < numV; j++) {
                edge[i][j] = 0;  // 将所有边初始化为0
            }
        }

        // 解析边关系并添加边
        i = 0;
        while (i < e.length()) {
            if (e[i] == '(') {
                char u = e[i + 1];
                char w = e[i + 3];

                int uIndex = Index(u);
                int wIndex = Index(w);
                
                // 添加边并增加边计数
                if (uIndex != -1 && wIndex != -1) {
                    edge[uIndex][wIndex] = 1;
                    numE++;
                }
            }
            i++;
        }
    }

    // 返回字符对应的索引
    int Index(char find) {
        for (int i = 0; i < numV; i++) {
            if (find == Verticles[i]) return i;
        }
        return -1;
    }
};

// 打印每个顶点的出度和入度
void PrintV(MGraph G) {
    int out[MAXV], in[MAXV];
    for (int i = 0; i < G.numV; i++) out[i] = in[i] = 0;

    // 计算出度和入度
    for (int i = 0; i < G.numV; i++) {
        for (int j = 0; j < G.numV; j++) {
            if (G.edge[i][j] == 1) {
                out[i]++;
                in[j]++;
            }
        }
    }

    // 输出每个顶点的信息
    for (int i = 0; i < G.numV; i++) {
        cout << G.Verticles[i] << " 出度: " << out[i] << " 入度: " << in[i] << endl;
    }
}

int main() {
    string v, e;
    cin >> v >> e;
    MGraph G(v, e);
    PrintV(G);
    return 0;
}

