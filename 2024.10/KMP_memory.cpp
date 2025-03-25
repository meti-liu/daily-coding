#include <string>
#include <iostream>
#include <vector>
using namespace std;


void GetNext(string t,int* next)
{
    int j=0;
    int k=-1;
    next[0]=-1;
    while(j<t.length()-1)
    {
        if(t[j]==t[k]||k==-1)
        {
            j++;
            k++;
            next[j]=k;
        }
        else k=next[k];
    }
}

int KMP(string s,string t)
{  
    int n=s.length();
    int m=t.length();
    int* next=new int();
    GetNext(t,next);
    int i=0;int j=0;
    while(i<n&&j<m)
    {
        if(j==-1||s[i]==t[j])
        {
            i++;
            j++;
        }
        else j=next[j];
    }
    if(j>=m) return i-j;
}