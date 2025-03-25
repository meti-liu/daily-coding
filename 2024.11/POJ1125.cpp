#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
const int INF=10000;
int e[105][105];
int dist[105];
int s[105];
int line[105];
int Max[105];


void debugPrint(int dist[], int n, int Max[]) 
{
    // 输出调试信息，查看每次Dijkstra迭代后的dist[]和Max[]
    cout << "dist[]: ";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;

    cout << "Max[]: ";
    for (int i = 1; i <= n; i++) {
        if (Max[i] == INF) cout << "INF ";
        else cout << Max[i] << " ";
    }
    cout << endl;
}

int main()
{
    ifstream ifs("in.txt");
    int n,t;//以t作为起点,因此本算法时间复杂度为O（n³）
    ifs>>n;   


    for(int j=1;j<=n;j++)
    for(int k=1;k<=n;k++)
    {
        e[j][k]=INF;
    }

    for(int j=1;j<=n;j++)//通过输入来构建图
    {
        int num;
        ifs>>num;
        if (num == 0) continue;
        for(int p=1;p<=2*num;p++)ifs>>line[p];
        for(int p=1;p<=num;p++) e[j][line[2*p-1]]=line[2*p];
    }

 


    for(int i=1;i<=n;i++)
    {
        t=i;
        Max[t]=0;




        for(int j=1;j<=n;j++)
        {
            dist[j]=e[t][j];//以t为起点开始初始化dijkstra算法
            s[j]=0;
        } 
        
        dist[t]=0;
        s[t]=1;


        for(int j=1;j<=n-1;j++)//进行n-1轮更新操作
        {
            int u=-1;
            int min=INF;

            for(int k=1;k<=n;k++)
            {
                if(s[k]==0&&dist[k]!=INF)
                {
                    if(dist[k]<min)
                    {
                        min=dist[k];
                        u=k;
                    }
                }
            }
            if(u==-1) break;
            //已经找到最小dist的下标u
            s[u]=1;

            for(int k=1;k<=n;k++)//开始比较dist+e与dist的大小,并更新dist
            {
                if(s[k]==0&&e[u][k]!=INF)
                {
                    if(dist[k]>dist[u]+e[u][k])
                    {
                        dist[k]=dist[u]+e[u][k];
                    }
                }
            }


        }



        for(int j=1;j<=n;j++)
        {
            if(dist[j]==INF)
            {
                Max[t]=INF;
                break;
            }
            if(dist[j]>Max[t]) Max[t]=dist[j];
        }
        
        //debugPrint(dist, n, Max);

    }

    int minMax=INF;
    int Index=-1;
    for(int i=1;i<=n;i++)//找到Max[t]中最小的
    {
       if(Max[i]<minMax)
       {
           minMax=Max[i];
           Index=i;
       }  
    } 
    
    if (minMax == INF) cout << "disjoint";

    else cout << Index << " " << minMax;

    return 0;
}