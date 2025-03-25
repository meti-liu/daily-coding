
#include <iostream>  
#include <string>  
#include <vector>  
#include <unordered_map>  
using namespace std;

const int maxV = 100;
typedef struct 
{
    int numberVertices, numEdges;
    char VerticesList[maxV];
    int edge[maxV][maxV];
} MGraph;

int printVertices(MGraph G) 
{
    int indegree, outdegree, count = 0;
    for (int i = 0; i < G.numberVertices; i++) 
    {
        indegree = 0;
        outdegree = 0;
        for (int j = 0; j < G.numberVertices; j++) {
            outdegree += G.edge[i][j];
        }
        for (int j = 0; j < G.numberVertices; j++) {
            indegree += G.edge[j][i];
        }
        if (outdegree > indegree) {
            if (count > 0) {
                cout << " ";
            }
            cout << G.VerticesList[i];
            count++;
        }
    }
    cout << endl << "Number of K vertices: " << count << endl;
    return count;
}

int main() {
    MGraph G;
    vector<char> v;
    string s, ss;
    getline(cin, s);  
    for (int i = 1; i < s.length() - 1; i++) { 
        if (s[i] != ',') {
            v.push_back(s[i]);
        }
    }
    int n = v.size();
    G.numberVertices = n;
    G.numEdges = 0; 

  
    for (int i = 0; i < n; i++) {
        G.VerticesList[i] = v[i];
        for (int j = 0; j < n; j++) {
            G.edge[i][j] = 0;
        }
    }

    unordered_map<char, int> charToIndex;
    for (int i = 0; i < n; i++) {
        charToIndex[v[i]] = i;
    }

    getline(cin, ss); 
    for (int i = 0, len = ss.length(); i < len; ) {
        if (ss[i] == '(') {
            i++; // 跳过'('  
            char a1 = ss[i];
            i += 2; // 跳过','和空格（如果有的话）  
            char a2 = ss[i];
            i++; // 跳过')'前的空格（如果有的话），并准备跳过')'  
            while (ss[i] != ')') i++; // 跳过')'  
            i++; // 跳过')'后的空格（如果有的话），准备进入下一个字符或结束  

            
            G.edge[charToIndex[a1]][charToIndex[a2]] = 1;
            G.numEdges++;  
        }
        else {
            i++; 
        }
    }

    cout << "K vertices: ";
    printVertices(G);

    return 0;
}