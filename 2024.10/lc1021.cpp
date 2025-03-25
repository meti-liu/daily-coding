#include<stack>
#include<string>
using namespace std;

string Remove(string s)
{
    string ans;
    int i=0;
    bool flag=false;
    stack<char> st;
    while(i<s.length())
    {
        if(s[i]=='(')
        {
            if(flag==true)  st.push(s[i]);
        }
        if(s[i]==')')
        {
            st.pop();
        }
    }
}