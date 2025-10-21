#include <stdio.h>
#include <iostream>
int n,m,ans;
int main()
{
    std:: cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        int x = i;
        while(x)
        {
            if(x % 10 == m)
                ans++;
            x /= 10;
        }
    }
    std::cout << ans << std::endl;
    return 0;  //NA....
}//
// Created by ZNArk on 2025/10/13.
//