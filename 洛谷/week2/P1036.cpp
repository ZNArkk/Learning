//
#include <stdio.h>
#include <iostream>
#define LL long long
LL a[100],ans;
int m,n;
void dfs(int sum,int step,int less)
{
    int flag = 1;
    if(less == n)
    {
        for(int i = 2 ; i * i <= sum ; i++)
        {
            if(sum % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            ans++;
        return;
    }
    for(int i = step ; i <= m ; i++)
        dfs(sum + a[i] , i + 1 , less + 1);
}
int main()
{
    std::cin >> m >> n;
    for(int i = 1 ; i <= m ; i++)
        std::cin >> a[i];
    dfs(0,1,0);
    std::cout << ans << std::endl;
    return 0; //Zk...
}
// Created by ZNArk on 2025/10/21.
//