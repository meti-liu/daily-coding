#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution 
{
public:
    string str[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> result;
    string combine;
    void dfs(string &digits, int idx, string &combine,vector<string>& result)
    {
        if(idx==digits.length())
        {
            result.push_back(combine);
            return;
        }
        string s=str[digits[idx]-'0'];
        for(int i=0;i<s.length();i++)
        {
            combine.push_back(s[i]);
            dfs(digits,idx+1,combine,result);
            combine.pop_back();
        }
        
    }

    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty()) return result;
        dfs(digits,0,combine,result);
        return result;
    }

    
};