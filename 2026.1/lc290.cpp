#include<iostream>
#include<string>
#include<unordered_map>
#include<sstream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        //split s by using iss tool
        vector<string> words;
        istringstream iss(s);
        string w;
        while(iss>>w) words.push_back(w);

        if(words.size()!=pattern.size()) return false;
        //hashmap: p2w & w2p
        unordered_map<char,string> p2w;
        unordered_map<string,char> w2p;

        //map[key]=value  map.find(key)
        for(int i=0;i<pattern.size();i++)
        {
            if(!p2w.count(pattern[i])) p2w[pattern[i]]=words[i];
            else if(p2w[pattern[i]]!=words[i]) return false;
        }

        for(int i=0;i<words.size();i++)
        {
            if(!w2p.count(words[i])) w2p[words[i]]=pattern[i];
            else if(w2p[words[i]]!=pattern[i]) return false;
        }

        return true;

    }
};