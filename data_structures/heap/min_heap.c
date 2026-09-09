/* C | heap: min heap. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 小根堆结构体
typedef struct {
    int* data;   // 存储堆元素的数组
    int size;    // 当前堆中元素的数量
    int capacity;// 堆的最大容量
} MinHeap;

// 初始化小根堆
MinHeap* initMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (int*)malloc(sizeof(int) * (capacity + 1));  // 索引从1开始方便计算
    heap->size = 0;
    heap->capacity = capacity;
    heap->data[0] = INT_MIN;  // 哨兵，简化边界判断
    return heap;
}

// 交换两个元素
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 向上调整（插入时使用）
void shiftUp(MinHeap* heap, int index) {
    // 当当前节点小于父节点时，交换并继续向上
    while (index > 1 && heap->data[index] < heap->data[index / 2]) {
        swap(&heap->data[index], &heap->data[index / 2]);
        index /= 2;
    }
}

// 向下调整（删除时使用）
void shiftDown(MinHeap* heap, int index) {
    int i = index;
    int j = 2 * i;  // 左子节点
    
    while (j <= heap->size) {
        // 找到左右子节点中较小的那个
        if (j + 1 <= heap->size && heap->data[j + 1] < heap->data[j]) {
            j++;
        }
        
        // 如果父节点小于子节点，满足小根堆特性，退出
        if (heap->data[i] < heap->data[j]) {
            break;
        }
        
        // 否则交换并继续向下
        swap(&heap->data[i], &heap->data[j]);
        i = j;
        j = 2 * i;
    }
}

// 插入元素
void push(MinHeap* heap, int value) {
    if (heap->size >= heap->capacity) {
        printf("堆已满，无法插入\n");
        return;
    }
    
    heap->size++;
    heap->data[heap->size] = value;  // 插入到最后
    shiftUp(heap, heap->size);       // 向上调整
}

// 删除并返回堆顶元素（最小值）
int pop(MinHeap* heap) {
    if (heap->size == 0) {
        printf("堆为空，无法删除\n");
        return INT_MIN;
    }
    
    int top = heap->data[1];                // 堆顶元素（索引1）
    heap->data[1] = heap->data[heap->size]; // 将最后一个元素移到堆顶
    heap->size--;                           // 元素数量减1
    shiftDown(heap, 1);                     // 向下调整
    
    return top;
}

// 获取堆顶元素（最小值）
int top(MinHeap* heap) {
    if (heap->size == 0) {
        printf("堆为空\n");
        return INT_MIN;
    }
    return heap->data[1];
}

// 判断堆是否为空
int isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

// 获取堆的大小
int size(MinHeap* heap) {
    return heap->size;
}

// 打印堆元素
void printHeap(MinHeap* heap) {
    for (int i = 1; i <= heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

// 释放堆内存
void freeHeap(MinHeap* heap) {
    free(heap->data);
    free(heap);
}

// 测试小根堆
int main() {
    MinHeap* heap = initMinHeap(10);  // 创建容量为10的小根堆
    
    push(heap, 5);
    push(heap, 3);
    push(heap, 8);
    push(heap, 1);
    push(heap, 2);
    
    printf("堆元素: ");
    printHeap(heap);  // 输出: 1 2 8 5 3
    
    printf("堆顶元素: %d\n", top(heap));  // 输出: 1
    printf("堆大小: %d\n", size(heap));    // 输出: 5
    
    pop(heap);
    printf("删除堆顶后元素: ");
    printHeap(heap);  // 输出: 2 3 8 5
    
    freeHeap(heap);
    return 0;
}

