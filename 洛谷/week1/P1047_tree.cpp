//
#include <stdio.h>
#include <iostream>
const int N = 1e4 + 10;
int l,m,ans,a[N];
int main() {
    std::cin >> l >> m;
    for(int i = 0; i < m; i++) {
        int x,y;
        std::cin >> x >> y;
        for (int j = x ; j <= y ; j++)
            a[j] = 1;
    }
    for (int i = 0 ; i <= l ; i++) {
        if (!a[i])
            ans++;
    }
    std::cout << ans;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/12.
//