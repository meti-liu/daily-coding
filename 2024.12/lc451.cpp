#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
void shellsort(vector<int>& arr)
{
    int n=arr.size();
    for(int gap=n/2;gap>0;gap/=2)
    {
        for(int i=gap;i<n;i++)//注意这里取不到n，插入排序同理
        {
            int tmp=arr[i];
            int j=i;
            while(j>=gap&&arr[j-gap]>tmp)//注意是j-gap和tmp比较
            {
                arr[j]=arr[j-gap];
                j-=gap;

            }
            arr[j]=tmp;
        }
    }

}
int main()
{
    ifstream ifs("in.txt");
    ofstream ofs("out.txt");
    string line;
    getline(ifs,line);
    vector<int> data;
    istringstream iss(line);
    int num;
    while(iss>>num)
    {
        data.push_back(num);
    }
    shellsort(data);
    for(int i=0;i<data.size();i++) ofs<<data[i]<<" ";
    
}