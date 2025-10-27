//
#include <stdio.h>
#include <iostream>
#define LL long long
const int N = 1e5 + 10;
int n,a[N],b[N];
//LL ans;
void mergesort(int l,int r) {
    if (l >= r) return;  //边界
    int m = (l + r) / 2;
    mergesort(l,m);  //分治
    mergesort(m + 1,r);
    int i = l,j = m + 1,k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else {
            b[k++] = a[j++];
            //  ans += m - i + 1;  逆序对
        }
    }
    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = b[i];
}
int main() {
    std::cin >> n;
    for (int i = 1 ; i <= n ; i++)
        std::cin >> a[i];
    mergesort(1,n);
    // std::cout << ans << std::endl;
    for (int i = 1 ; i <= n ; i++)
        std::cout << a[i] << " ";
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/27.
//