//
#include <stdio.h>
#include <iostream>
#define LL long long
const int N = 1e6 + 10;
LL a[N];
LL L,m,n;
bool cheak(LL x)
{
    LL sum = 0;
    LL ans = 0;
    for(int i = 0 ; i <= m ; i++)
    {
        if(a[i] - sum >= x)
            sum = a[i];
        else
        {
            ans++;
            if(ans > n)
                return false;
        }
    }
    return true;
}
int main()
{
    std::cin >> L >> m >> n;
    for(int i = 0 ; i < m ; i++)
        std::cin >> a[i];
    a[m] = L;
    int l = 0;
    int r = L;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(cheak(mid))
            l = mid;
        else
            r = mid - 1;
    }
    std::cout << l << std::endl;
    return 0;  //m...
}
// Created by ZNArk on 2025/11/4.
//