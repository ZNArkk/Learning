//
#include <stdio.h>
#include <iostream>
// 最大数组大小
const int N = 5e5 + 10;
// n: 数组大小, m: 操作次数, a: 原数组, tree: 树状数组
int n,m,a[N],b[N],tree[N];
// 计算 lowbit：二进制表示中最低位的1及其后面的0
int lowbit(int k) {
    return k & -k;
}
// 单点更新：在位置 id 处加上 x
void update(int id,int x) {
    for (int i = id ; i <= n ; i += lowbit(i))
        tree[i] += x;
}
// 前缀和查询：查询 [1, x] 的和
int query(int x) {
    int sum = 0;
    for (; x ; x -= lowbit(x))
        sum += tree[x];
    return sum;
}
int main() {
    std::cin >> n >> m;
    // 用差分数组初始化树状数组
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> a[i];
        update(i,a[i] - a[i - 1]);
    }
    // 处理 m 次操作
    for (int i = 1,type,x,y,k ; i <= m ; i++) {
        std::cin >> type;
        // type=1: 区间 [x, y] 加上 k
        if (type == 1) {
            std::cin >> x >> y >> k;
            update(x,k);
            update(y + 1,-k);
        }
        // type=2: 查询位置 x 的值（前缀和）
        else {
            std::cin >> x;
            std::cout << query(x) << std::endl;
        }
    }
    return 0;  //Zk...
}
// Created by ZNArk on 2025/12/9.
//