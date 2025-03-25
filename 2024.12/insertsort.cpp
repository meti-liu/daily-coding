#include <iostream>
using namespace std;

// 插入排序函数
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // 当前要插入的元素
        int j = i - 1;
        
        // 找到插入位置并移动元素
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // 将大于key的元素向右移动
            --j;
        }
        
        // 插入key
        arr[j + 1] = key;
    }
}

void sort(int a[],int low,int high)
{
    for(int i=low;i<=high;i++)
    for(int j=i;j<=high;j++)
    {
        if(a[i]>a[j]) swap(a[i],a[j]);
    }
}

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6}; // 测试数据
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "排序前的数组: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "排序后的数组: ";
    printArray(arr, n);

    return 0;
}
