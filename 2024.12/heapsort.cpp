#include<iostream>
using namespace std;

void siftDown(int R[], int low, int high) {
    int i = low;                  // 当前节点索引
    int j = 2 * i + 1;            // 左孩子索引

    // 如果左孩子越界，则终止递归
    if (j > high) return;

    // 如果右孩子存在且右孩子比左孩子大，则选择右孩子
    if (j < high && R[j] < R[j + 1]) j++;

    // 如果当前节点小于孩子节点，则交换并递归调整
    if (R[i] < R[j]) 
    {
        swap(R[i], R[j]);         // 交换当前节点与较大的孩子
        siftDown(R, j, high);    // 递归调整子树
    }

    // 如果没有孩子比当前节点大，递归终止（隐含逻辑）
}

void HeapSort(int R[],int n)
{
    for(int i=n/2-1;i>=0;i--)  siftDown(R,i,n-1);//初始建堆

    for(int i=n-1;i>0;i--)
    {
        swap(R[0],R[i]);
        siftDown(R,0,i-1);
    }
}
