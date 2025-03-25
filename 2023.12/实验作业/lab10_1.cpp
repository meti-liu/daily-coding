#include <iostream>
#include<vector>
#include <algorithm>  // 包含STL算法，比如find和sort
#include <functional> // 包含greater
using namespace std;


int main()
{
    //int a[5]={3,1,4,2,5};
    vector<int>a={3,1,4,2,5};
    int n;
    cin>>n;//需要查找的数
    auto p=find(a.begin(),a.end(),n);//STL查找函数，因为返回迭代器类型，所以用auto
    int index=distance(a.begin(),p)+1;
    cout<<index<<endl;

    sort(a.begin(),a.end(),greater<int>());//降序
    for(auto n:a) cout<<n<<" ";
    cout<<endl;
    sort(a.begin(),a.end());//升序
    for(auto n:a) cout<<n<<" ";
    return 0;
}