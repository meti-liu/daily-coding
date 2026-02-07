#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int maxL=0;
        unordered_set<char> set;
        int i=0;
        for(int j=0;j<s.size();j++)
        {
            while(set.find(s[j])!=set.end())
            {
                set.erase(s[i]);
                i++;
            }

            set.insert(s[j]);
            maxL=max(maxL,j-i+1);
        }
        return maxL;
    }
};

