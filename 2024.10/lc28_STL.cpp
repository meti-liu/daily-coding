#include<iostream>
#include<string>
using namespace std;
int strStr(string haystack, string needle) 
{
    int pos=haystack.find(needle);
    if(pos==string::npos) return -1;
    else return pos;
}