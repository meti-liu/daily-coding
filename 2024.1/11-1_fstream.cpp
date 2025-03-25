#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    //先写入“已成功写入！”
    ofstream outfile("11-1.txt");
    if (outfile.is_open())//判断是否成功打开
    {
        outfile << "success writing";
        outfile.close();
    }
    else
    {
        cout << "unable to open file";
        return 1;
    }

    //读取文件
    ifstream infile("11-1.txt");
    if (infile.is_open())
    {
        string s;
        while (getline(infile, s))
        {
            cout << s << endl;
        }
        infile.close();
    }
    else
    {
        cerr << "unable to open";
        return 1;
    }
    return 0;
}