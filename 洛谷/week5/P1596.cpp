//
#include<stdio.h>
#include<iostream>
int n,m;
char a[101][101];
int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {1,0,-1,1,0,-1,1,-1};
int used[101][101];
void dfs(int x ,int y)
{
    used[x][y] = 1;
    for(int i = 0 ; i < 8 ; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 0 && xx < n && yy >= 0 && yy < m && !used[xx][yy])
            dfs(xx,yy);
    }
    return;
}
int main()
{
    int ans = 0;
    std::cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            std::cin >> a[i][j];
            if(a[i][j] == '.')
                used[i][j] = 1;
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(used[i][j] == 0)
            {
                ans++;
                dfs(i,j);
            }
        }
    }
    std::cout << ans;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/11/12.
//