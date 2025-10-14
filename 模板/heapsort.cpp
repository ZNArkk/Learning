//
#include <stdio.h>
#include <iostream>
const int MAX = 2e5 + 10;
int n,a[MAX],tot;
void swap(int &a,int &b) {
    int t = a;
    a = b;
    b = t;
}
void down(int i,int x) {  //向下维护
    int s = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l <= x && a[s] < a[l]) s = l;
    if (r <= x && a[s] < a[r]) s = r;
    if(s != i) {
        swap(a[i],a[s]);
        down(s,x);
    }
}
void buildheap(int x) {  //建立大顶堆
    for (int i = (x + 1) / 2 - 1; i >= 0; i--)
        down(i, x);
}
void heapsort(int x) {  //堆排
    while (tot) {
        swap(a[tot],a[0]);
        down(0,--tot);
    }
}
int main() {
    std::cin >> n;
    tot = n - 1;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    buildheap(tot);
    heapsort(tot);
    for (int i = 0; i < n; i++)
        std::cout << a[i] << ' ';
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/13.
//