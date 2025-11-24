//
#include <stdio.h>
#include <iostream>
int n,ans,a[1005][1005];
int main()
{
    std::cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= i ; j++)
            std::cin >> a[i][j];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= i ; j++)
        {
            a[i][j] += std::max(a[i - 1][j - 1],a[i - 1][j]);
            ans = std::max(ans,a[i][j]);
        }
    }
    std::cout << ans << std::endl;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/11/25.
//