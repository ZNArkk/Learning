//
#include <stdio.h>
#include <iostream>
#include <stack>
#define LL long long
const int N = 1e6 + 10;
LL n,h[N],v[N],t1[N],t2[N],ans[N],maxx;
std::stack<int> q;
int main()
{
    std::cin >> n;
    for(int i = 1 ; i <= n ; i++)
        std::cin >> h[i] >> v[i];
    q.push(1);
    for(int i = 2 ; i <= n ; i++)
    {
        int x = q.top();
        if(h[i] <= h[x])
            q.push(i);
        else
        {
            while(h[i] > h[x])
            {
                t1[x] = i;
                q.pop();
                if(q.empty())
                    break;
                x = q.top();
            }
            q.push(i);
        }
    }
    while(!q.empty())
        q.pop();
    q.push(n);
    for(int i = n - 1 ; i ; i--)
    {
        int x = q.top();
        if(h[i] <= h[x])
            q.push(i);
        else
        {
            while(h[i] > h[x])
            {
                t2[x] = i;
                q.pop();
                if(q.empty())
                    break;
                x = q.top();
            }
            q.push(i);
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        ans[t1[i]] += v[i];
        ans[t2[i]] += v[i];
    }
    for(int i = 1 ; i <= n ; i++)
        maxx = std::max(maxx,ans[i]);
    std::cout << maxx;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/12/2.
//