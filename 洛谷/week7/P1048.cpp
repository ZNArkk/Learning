//
#include <stdio.h>
#include <iostream>
const int N = 1e3 + 10;
struct node
{
    int x,y;
}a[110];
int dp[N];
int t,m;
int main()
{
    std::cin >> t >> m;
    for(int i = 1 ; i <= m ; i++)
        std::cin >> a[i].x >> a[i].y;
    for(int i = 1 ; i <= m ; i++)
    {
        for(int j = t ; j ; j--)
        {
            if(j >= a[i].x)
                dp[j] = std::max(dp[j],dp[j - a[i].x] + a[i].y);
        }
    }
    std::cout << dp[t] << std::endl;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/11/25.
//