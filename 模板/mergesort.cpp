//
#include <stdio.h>
#include <iostream>
#define LL long long
// 最大数组大小
const int N = 5e5 + 10;
// n: 数组大小, a: 原数组, b: 辅助数组
int n,a[N],b[N];
//LL ans;  // 逆序对计数（注释掉）
// 归并排序：对区间 [l, r] 进行排序
void mergesort(int l,int r) {
    if (l >= r) return;  // 边界：只有一个元素或空区间
    int m = (l + r) / 2;
    // 分治：递归排序左右区间
    mergesort(l,m);
    mergesort(m + 1,r);
    // 合并：将两个有序区间合并到辅助数组b中
    int i = l,j = m + 1,k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else {
            b[k++] = a[j++];
          //  ans += m - i + 1;  // 逆序对计数（注释掉）
        }
    }
    // 处理剩余元素
    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    // 将辅助数组b中的结果复制回原数组a
    for (i = l; i <= r; i++) a[i] = b[i];
}
int main() {
    std::cin >> n;
    // 读入数组
    for (int i = 1 ; i <= n ; i++)
        std::cin >> a[i];
    // 归并排序
    mergesort(1,n);
   // std::cout << ans << std::endl;  // 输出逆序对数量（注释掉）
    // 输出排序后的数组
    for (int i = 1 ; i <= n; i++)
        std::cout << a[i] << " ";
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/14.
//