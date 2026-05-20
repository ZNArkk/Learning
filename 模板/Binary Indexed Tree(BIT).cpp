//
#include <stdio.h>
#include <iostream>
// 最大数组大小
const int N = 5e5 + 10;
// n: 数组大小, m: 操作次数, type: 操作类型, p/q: 参数, a: 原数组, tree: 树状数组
int n,m,type,p,q,a[N],tree[N];
// 计算 lowbit：二进制表示中最低位的1及其后面的0
int lowbit(int x) {  //二进制最小非0位
    return x & (-x);
}
// 单点更新：在位置 id 处加上 x
void add(int id,int x) {  //添加操作
    for (int i = id ; i <= n ; i += lowbit(i))
        tree[i] += x;
}
// 前缀和查询：查询 [1, x] 的和
int query(int x) {  //查询操作
    int ans = 0;
    for (; x ; x -= lowbit(x))
        ans += tree[x];
    return ans;
}
int main() {
    std::cin >> n >> m;
    // 初始化树状数组
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> a[i];
        add(i,a[i]);
    }
    // 处理 m 次操作
    for (int i = 0 ; i < m ; i++) {
        std::cin >> type >> p >> q;
        // type=1: 在位置 p 处加上 q
        if (type == 1)
            add(p,q);  //初始化
        // type=2: 查询区间 [p, q] 的和
        else
            std::cout << query(q) - query(p - 1) << std::endl;
    }
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/14.

//
