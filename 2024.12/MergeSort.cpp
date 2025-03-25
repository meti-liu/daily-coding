#include<iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
void Merge(vector<int>& arr,int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;
    vector<int> L(n1);
    vector<int> R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // 复制剩余元素
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void MergeSort(vector<int>& arr,int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        Merge(arr,left,mid,right);
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
    vector<int> arr;
    while(iss>>num) arr.push_back(num);
    MergeSort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++) ofs<<arr[i]<<" ";
}