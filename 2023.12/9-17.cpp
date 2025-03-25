#include<iostream>
using namespace std;
template<typename T>
int Search(T list[],int n,T key)//类型为T的数组,n个元素,每个元素类型均为T
{
    for(int i=0;i<n;i++)
    {
        if(key==list[i]) return i+1;
    }
        return -1;
}
int main()
{
    cout<<"data:"<<endl;
    int data[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
    for(int i=0;i<20;i++) cout<<data[i]<<" ";
    int key;
    cin>>key;
    cout<<endl<<"location:"<<Search<int>(data,20,key);
    return 0;
}