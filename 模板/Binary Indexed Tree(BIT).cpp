//
#include <stdio.h>
#include <iostream>
const int N = 5e5 + 10;
int n,m,type,p,q,a[N],tree[N];
int lowbit(int x) {  //二进制最小非0位
    return x & (-x);
}
void add(int id,int x) {  //添加操作
    for (int i = id ; i <= n ; i += lowbit(i))
        tree[i] += x;
}
int query(int x) {  //查询操作
    int ans = 0;
    for (; x ; x -= lowbit(x))
        ans += tree[x];
    return ans;
}
int main() {
    std::cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> a[i];
        add(i,a[i]);
    }
    for (int i = 0 ; i < m ; i++) {
        std::cin >> type >> p >> q;
        if (type == 1)
            add(p,q);  //初始化
        else
            std::cout << query(q) - query(p - 1) << std::endl;
    }
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/14.

//
