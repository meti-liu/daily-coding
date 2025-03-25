#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
    vector<int> data;

public:
    // 构造函数
    Array(const vector<int>& initData) : data(initData) {}

    // 插入排序
    void insertionSort() 
    {
        int n = data.size();
        for (int i = 1; i < n; i++) 
        {
            int key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key) 
            {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }

    // 选择排序
    void selectionSort() {
        int n = data.size();
        for (int i = 0; i < n - 1; i++) 
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) 
            {
                if (data[j] < data[minIndex]) 
                {
                    minIndex = j;
                }
            }
            swap(data[i], data[minIndex]);
        }
    }

    // 冒泡排序
    void bubbleSort() {
        int n = data.size();
        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n - i - 1; j++) 
            {
                if (data[j] > data[j + 1]) 
                {
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }

    // 顺序查找
    int linearSearch(int value) {
        for (size_t i = 0; i < data.size(); i++) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1; // 如果未找到
    }

    // 输出数组元素
    void print() {
        for (int i : data) {
            cout << i << " ";
        }
        cout << std::endl;
    }
};

int main() {
    vector<int> numbers = {5, 3, 4, 1, 2};
    Array arr(numbers);

    cout << "Original array: ";
    arr.print();

    arr.insertionSort();
    std::cout << "After insertion sort: ";
    arr.print();

    arr.selectionSort();
    std::cout << "After selection sort: ";
    arr.print();

    arr.bubbleSort();
    std::cout << "After bubble sort: ";
    arr.print();

    int index = arr.linearSearch(3);
    if (index != -1) {
        cout << "Element 3 found at index: " << index << endl;
    } else {
        cout << "Element 3 not found." << endl;
    }

    return 0;
}
