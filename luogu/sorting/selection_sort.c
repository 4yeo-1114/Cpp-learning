/* C | sorting: selection sort. */
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        // 假设当前位置是最小值
        minIndex = i;
        // 从 i+1 开始找真正的最小值
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // 如果最小值不在当前位置，就交换
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("原始数组: ");
    printArray(arr, n);

    selectionSort(arr, n);
    printf("排序后:   ");
    printArray(arr, n);
    return 0;
}
