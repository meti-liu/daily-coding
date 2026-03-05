#include<vector>
#include<iostream>
#include<queue>
using namespace std;
class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<int,int>> q;
        int time=0,fresh=0;
        int m=grid.size();
        int n=grid[0].size();

        for(int x=0;x<m;x++)
        for(int y=0;y<n;y++)
        {
            if(grid[x][y]==1) fresh++;
            else if(grid[x][y]==2)
            {
                q.push(pair{x,y});

            }
        }

        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,-1,1};
        while(!q.empty())
        {
            int l=q.size();
            for(int i=0;i<l;i++)
            {
                pair<int,int> a=q.front();
                for(int j=0;j<=3;j++)
                {
                    int x=a.first+dx[j];
                    int y=a.second+dy[j];
                    if(x>=0&&y>=0&&x<m&&y<n&&grid[x][y]==1)
                    {
                        q.push(pair{x,y});
                        grid[x][y]=2;
                        fresh--;
                    }

                }
                q.pop();
            }
            time++;
        }

        if(fresh!=0) return -1;
        else return max(0,time-1);

    }
};