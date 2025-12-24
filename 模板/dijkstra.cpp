//
#include <stdio.h>
#include <iostream>
#include <queue>
const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int INF = 0x3f3f3f3f;
struct node {
    int id,num;
    friend bool operator <(node a,node b) {
        return a.num > b.num;
    }
};
int n,m,s,w[M],to[M],head[M],next[M],dis[N],vis[N],cnt;
void add(int u,int v,int k) {
    to[++cnt] = v;
    w[cnt] = k;
    next[cnt] = head[u];
    head[u] = cnt;
}
void dijkstra() {
    for (int i = 1 ; i <= n ; i++)
        dis[i] = INF;
    std::priority_queue<node > p;
    dis[s] = 0;
    p.push(node{1,dis[s]});
    while (!p.empty()) {
        node t = p.top();
        p.pop();
        int idx = t.id;
        int minn = t.num;
        if (vis[idx])
            continue;
        vis[idx] = 1;
        for (int i = head[idx] ; i ; i = next[i]) {
            int v = to[i];
            if (!vis[v] && dis[v] > w[i] + minn) {
                dis[v] = w[i] + minn;
                p.push((node){v,dis[v]});
            }
        }
    }
}
int main() {
    std::cin >> n >> m >> s;
    for (int i = 1 ; i <= m ; i++) {
        int a,b,c;
        std::cin >> a >> b >> c;
        add(a,b,c);
    }
    dijkstra();
    for (int i = 1 ; i <= n ; i++)
        std::cout << dis[i] << " ";
    return 0;  //Zk...
}
// Created by ZNArk on 2025/12/19.
//