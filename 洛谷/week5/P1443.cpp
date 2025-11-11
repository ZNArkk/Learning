//
#include <stdio.h>
#include <queue>
using namespace std;
int n,m,x,y;
int a[405][405];
int dx[] = {1,1,-1,-1,2,2,-2,-2};
int dy[] = {2,-2,2,-2,1,-1,1,-1};
struct node {
    int xx,yy,step;
};
queue<node> s;
void bfs() {
    while (!s.empty()) {
        node f = s.front();
        s.pop();
        for (int i = 0 ; i < 8 ; i++) {
            int nx = f.xx + dx[i];
            int ny = f.yy + dy[i];
            int ns = f.step + 1;
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && a[nx][ny] == -1) {
                s.push((node){nx,ny,ns});
                a[nx][ny] = ns;
            }
        }
    }
    return;
}
int main() {
    scanf("%d%d%d%d",&n,&m,&x,&y);
    s.push((node){ x,y,0 });
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++)
            a[i][j] = -1;
    }
    a[x][y] = 0;
    bfs();
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1; j <= m; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;  //Zk...
}
// Created by ZNArk on 2025/11/12.
//