#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    //��д�롰�ѳɹ�д�룡��
    ofstream outfile("11-1.txt",std::ios::app);
    if (outfile.is_open())//�ж��Ƿ�ɹ���
    {
        outfile << "success writing";
        outfile.close();
    }
    else
    {
        cout << "unable to open file";
        return 1;
    }

    //��ȡ�ļ�
    ifstream infile("11-1.txt",std::ios::app);
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