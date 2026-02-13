#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;
class Solution 
{
public:
    unordered_set<int> col_set;
    unordered_set<int> add_set;
    unordered_set<int> sub_set;

    void dfs(int n,int row,vector<vector<string>>& result,vector<string>& cur,unordered_set<int>& col_set,unordered_set<int>& add_set,unordered_set<int>& sub_set)
    {
        if(row==n)
        {
            result.push_back(cur);
            return;
        }

        for(int col=0;col<n;col++)
        {
            if(col_set.count(col)||add_set.count(row+col)||sub_set.count(row-col))
            {
                cur[row][col]='.';
                continue;
            }
            else
            {
                cur[row][col]='Q';
                col_set.emplace(col);
                add_set.emplace(col+row);
                sub_set.emplace(row-col);
                dfs(n,row+1,result,cur,col_set,add_set,sub_set);
                col_set.erase(col);
                add_set.erase(col+row);
                sub_set.erase(row-col);
                cur[row][col]='.';
                
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> result;
        vector<string> cur(n,string(n,'.'));
        dfs(n,0,result,cur,col_set,add_set,sub_set);
        return result;
    }
};