//
#include <stdio.h>
#include <iostream>
#include <vector>
#define MOD 80112002
const int N = 5e3 + 10;
int n,m,ans,sum[N],flag[N];
std::vector<int> v[N];
int dfs(int x) {
    if (sum[x])
        return sum[x];
    if (v[x].empty())
        return sum[x] = 1;
    for (int i = 0 ; i < v[x].size() ; i++) {
        sum[x] = (sum[x] + dfs(v[x][i])) % MOD;
    }
    return sum[x];
}
int main() {
    std::cin >> n >> m;
    for (int i = 0 ; i < m; i++) {
        int x,y;
        std::cin >> x >> y;
        v[y].push_back(x);
        flag[x] = 1;
    }
    for (int i = 1 ; i <= n; i++) {
        if (!flag[i])
            ans = (ans + dfs(i)) % MOD;
    }
    std::cout << ans << std::endl;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/11/19.
//