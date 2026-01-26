#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
            if(st.empty()) return false;
            char t=st.top();
            if(s[i]==')')
            {
                if(t=='(') st.pop();
                else return false;
            } 
            if(s[i]==']')
            {
                if(t=='[') st.pop();
                else return false;
            } 
            if(s[i]=='}')
            {
                if(t=='{') st.pop();
                else return false;
            } 
        }

        return st.empty();
    }
};