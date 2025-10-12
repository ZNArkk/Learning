#include <stdio.h>
#include <iostream>
int n;
int a1,b1,c1,a2,b2,c2,a3,b3,c3;
int f(int a, int b)
{
    int k = n / a;
    if(n % a == 0)
        return b * k;
    return b * (k + 1);
}
int main()
{
    std::cin >> n;
    std::cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    c1 = f(a1,b1);
    c2 = f(a2,b2);
    c3 = f(a3,b3);
    int ans = std::min(c1,std::min(c2,c3));
    std::cout << ans << std::endl;
    return 0;  //NA....
}//
// Created by ZNArk on 2025/10/13.
//