#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    string ifileName = "11-9.txt";
    string ofileName = "11-9_out.txt";
    ifstream ifile(ifileName);
    ofstream ofile(ofileName);
    if (!ifile.is_open())
    {
        cout << "fail to open ifle" << endl;
        return 1;
    }

    if (!ofile.is_open())
    {
        cout << "fail to open ofle" << endl;
        return 1;
    }

    string line;
    int n = 0;
    while (getline(ifile, line))
    {
        n++;
        ofile << n << " " << line << endl;
    }
    ifile.close();
    ofile.close();

    return 0;
}