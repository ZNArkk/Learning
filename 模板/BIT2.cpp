//
#include <stdio.h>
#include <iostream>
const int N = 5e5 + 10;
int n,m,a[N],b[N],tree[N];
int lowbit(int k) {
    return k & -k;
}
void update(int id,int x) {
    for (int i = id ; i <= n ; i += lowbit(i))
        tree[i] += x;
}
int query(int x) {
    int sum = 0;
    for (; x ; x -= lowbit(x))
        sum += tree[x];
    return sum;
}
int main() {
    std::cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> a[i];
        update(i,a[i] - a[i - 1]);
    }
    for (int i = 1,type,x,y,k ; i <= m ; i++) {
        std::cin >> type;
        if (type == 1) {
            std::cin >> x >> y >> k;
            update(x,k);
            update(y + 1,-k);
        }
        else {
            std::cin >> x;
            std::cout << query(x) << std::endl;
        }
    }
    return 0;  //Zk...
}
// Created by ZNArk on 2025/12/9.
//