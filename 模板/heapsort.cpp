//
#include <stdio.h>
#include <iostream>
// 最大数组大小
const int MAX = 2e5 + 10;
// n: 数组大小, a: 原数组, tot: 堆的大小
int n,a[MAX],tot;
// 交换两个数
void swap(int &a,int &b) {
    int t = a;
    a = b;
    b = t;
}
// 向下调整：维护大顶堆性质
void down(int i,int x) {
    int s = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    // 找到当前节点和左右儿子中的最大值
    if (l <= x && a[s] < a[l]) s = l;
    if (r <= x && a[s] < a[r]) s = r;
    // 如果最大值不是当前节点，交换并继续向下调整
    if(s != i) {
        swap(a[i],a[s]);
        down(s,x);
    }
}
// 建堆：将数组调整为大顶堆
void buildheap(int x) {
    // 从最后一个非叶子节点开始向下调整
    for (int i = (x + 1) / 2 - 1; i >= 0; i--)
        down(i, x);
}
// 堆排序
void heapsort(int x) {
    // 每次将堆顶（最大值）交换到末尾，然后调整堆
    while (tot) {
        swap(a[tot],a[0]);
        down(0,--tot);
    }
}
int main() {
    std::cin >> n;
    tot = n - 1;
    // 读入数组
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    // 建堆
    buildheap(tot);
    // 堆排序
    heapsort(tot);
    // 输出排序后的数组
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/13.
//