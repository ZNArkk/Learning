//
#include <stdio.h>
#include <iostream>
#include <queue>
// 最大点数
const int N = 1e5 + 10;
// 最大边数
const int M = 2e5 + 10;
// 无穷大
const int INF = 0x3f3f3f3f;
// 优先队列节点：id为点编号，num为距离
struct node {
    int id,num;
    // 重载小于号，使优先队列成为小根堆
    friend bool operator <(node a,node b) {
        return a.num > b.num;
    }
};
// n: 点数, m: 边数, s: 起点, w: 边权, to: 边终点, head: 邻接表头, next: 邻接表后继, dis: 最短路距离, vis: 访问标记, cnt: 边计数器
int n,m,s,w[M],to[M],head[M],next[M],dis[N],vis[N],cnt;
// 加边：u->v，边权k
void add(int u,int v,int k) {
    to[++cnt] = v;
    w[cnt] = k;
    next[cnt] = head[u];
    head[u] = cnt;
}
// Dijkstra算法：求单源最短路径
void dijkstra() {
    // 初始化距离为无穷大
    for (int i = 1 ; i <= n ; i++)
        dis[i] = INF;
    std::priority_queue<node > p;
    // 起点距离为0
    dis[s] = 0;
    p.push(node{s,dis[s]});
    while (!p.empty()) {
        node t = p.top();
        p.pop();
        int idx = t.id;
        int minn = t.num;
        // 如果已经访问过，跳过
        if (vis[idx])
            continue;
        vis[idx] = 1;
        // 遍历邻接边，松弛操作
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
    // 读入m条边
    for (int i = 1 ; i <= m ; i++) {
        int a,b,c;
        std::cin >> a >> b >> c;
        add(a,b,c);
    }
    // 运行Dijkstra算法
    dijkstra();
    // 输出从起点到各点的最短距离
    for (int i = 1 ; i <= n ; i++)
        std::cout << dis[i] << " ";
    return 0;  //Zk...
}
// Created by ZNArk on 2025/12/19.
//