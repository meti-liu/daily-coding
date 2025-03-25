#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int a[2000000];
int partition(int arr[],int low,int high)
{
    int pivot=arr[high];//基准随便选，这里选最后一个
    int i=low;

    for(int j=low;j<high;j++)//不能取等
    {
        if(arr[j]<pivot)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);//最后和基准交换一轮
    return i;

}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pivot=partition(arr,low,high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);
    }
}
int main()
{
    ifstream ifs("in.txt");
    ofstream ofs("out.txt");
    string line;
    getline(ifs,line);
    istringstream iss(line);
    int num;
    int i=0;
    while(iss>>num)
    {
        a[i]=num;
        i++;
    }
    int n=i;
    quicksort(a,0,n-1);
    for(int i=n-1;i>=n-10;i--) ofs<<a[i]<<" ";
}