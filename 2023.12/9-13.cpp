#include<iostream>
#include<deque>//std自带的双向队列库
using namespace std;

int main()
{
    deque<char> deq;
    deq.push_back('A');//在队尾加入
    deq.push_back('B');
    deq.push_back('C');
    cout<<"Front:"<<deq.front()<<endl;//取队首元素
    cout<<"Back:"<<deq.back()<<endl;

    deq.push_front('D');
    cout<<"Front:"<<deq.front()<<endl;//取队首元素
    cout<<"Back:"<<deq.back()<<endl;
    return 0;
}