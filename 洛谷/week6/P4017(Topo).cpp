//
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#define MOD 80112002
const int N = 5e3 + 10;
int n,m,ans,sum[N],in[N];
std::vector<int> v[N];
std::queue<int> q;
void Topo() {
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        if (v[f].empty())
            ans = (ans + sum[f]) % MOD;
        for (int i = 0 ; i < v[f].size() ; i++) {
            sum[v[f][i]] = (sum[f] + sum[v[f][i]]) % MOD;
            in[v[f][i]]--;
            if (!in[v[f][i]]) q.push(v[f][i]);
        }
    }
}
int main() {
    std::cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int x,y;
        std::cin >> x >> y;
        v[x].push_back(y);
        in[y]++;
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!in[i]) {
            sum[i] = 1;
            q.push(i);
        }
    }
    Topo();
    std::cout << ans << std::endl;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/11/19.
//