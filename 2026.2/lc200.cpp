#include<vector>
#include<iostream>
using namespace std;
class Solution 
{
public:

    void dfs(vector<vector<char>>&grid,int x,int y,int row,int col)
    {
        if(x<0||y<0||x>=row||y>=col||grid[x][y]=='0') return;
        grid[x][y]='0';
        dfs(grid,x+1,y,row,col);
        dfs(grid,x-1,y,row,col);
        dfs(grid,x,y+1,row,col);
        dfs(grid,x,y-1,row,col);
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;

        for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]=='1')
            {
                ans++;
                dfs(grid,i,j,row,col);
            }
        }
        return ans;
    }
};