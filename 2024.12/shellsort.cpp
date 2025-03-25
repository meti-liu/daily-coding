void shellSort(int arr[], int n) {
    // 选择增量序列
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 使用插入排序对子序列进行排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            // 插入排序过程
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];//移动距离是gap
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}
