//
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
const int N = 1e4 + 10;
int a[N],n,t;
bool check(int x) {
    int sum = 0,tot = x + 1;
    std::priority_queue<int,std::vector<int>,std::greater<int> > p;
    for (int i = 1 ; i <= x ; i++)
        p.push(a[i]);
    while (!p.empty()) {
        sum = p.top();
        while (p.top() == sum && !p.empty())
            p.pop();
        while (p.size() < x && tot <= n)
            p.push(a[tot++] + sum);
    }
    if (sum > t)
        return false;
    return true;
}
int main() {
    std::cin >> n >> t;
    for (int i = 1 ; i <= n ; i++)
        std::cin >> a[i];
    int l = 1,r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }
    std::cout << l;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/11/19.
//