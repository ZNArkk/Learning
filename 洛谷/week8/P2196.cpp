//
#include <stdio.h>
#include <iostream>
int n,a[25],dp[25],s[25][25];
int lowbit(int x) {
    return x & -x;
}
int b(int x) {
    int sum = 0;
    while (x) {
        sum++;
        x /= 2;
    }
    return sum;
}
int f(int x) {
    int sum = 0;
    for (int i = x ; i ; i -= lowbit(i))
        sum += a[b(lowbit(i))];
    return sum;
}
int main() {
    std::cin >> n;
    for (int i = 1 ; i <= n ; i++)
        std::cin >> a[i];
    for (int i = 1 ; i < n ; i++) {
        int x;
        for (int j = i + 1 ; j <= n ; j++) {
            std::cin >> x;
            s[i][j] = x;
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        int sum = 1;
        for (int j = 2 ; j <= i ; j++)
            sum *= 2;
        dp[i] = sum;
    }
    for (int i = 1 ; i <= n ; i++) {
        int maxx = 0,t = 0;
        for (int j = i - 1 ; j ; j--) {
            if (f(dp[j]) > maxx && s[j][i]) {
                maxx = f(dp[j]);
                t = j;
            }
        }
        dp[i] += dp[t];
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (f(dp[i]) > f(dp[ans]))
            ans = i;
    }
    for (int i = dp[ans] ; i ; i -= lowbit(i))
        std::cout << b(lowbit(i)) << " ";
    std::cout << std::endl;
    std::cout << f(dp[ans]);
    return 0;  //Zk...
}
// Created by ZNArk on 2025/12/2.
//