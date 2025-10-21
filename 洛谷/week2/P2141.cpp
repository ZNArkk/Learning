//
#include <stdio.h>
#include <iostream>
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
int a[N],vis[N],num[N],ans = 0;
int n;
int maxx = -INF;
int main()
{
    std::cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        std::cin >> a[i];
        vis[a[i]] = 1;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = i + 1 ; j <= n ; j++)
        {
            num[a[i] + a[j]]++;
            maxx = std::max(maxx,a[i] + a[j]);
        }
    }
    for(int i = 1 ; i <= maxx ; i++)
    {
        if(num[i] && vis[i])
            ans++;
    }
    std::cout << ans << std::endl;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/21.
//