#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool Compare(int a,int b)
{
    return a>b;
}
int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        nums.push_back(num);
    }
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++) cout<<nums[i]<<" ";
    cout<<endl;
    sort(nums.begin(),nums.end(),Compare);
    for(int i=0;i<n;i++) cout<<nums[i]<<" ";

}