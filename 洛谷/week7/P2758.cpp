//
#include <stdio.h>
#include <iostream>
#include <string>
std::string str1,str2;
int l1,l2,dp[2001][2001];
int main() {
    std::cin >> str1 >> str2;
    l1 = str1.length();
    l2 = str2.length();
    for (int i = 1 ; i <= l1 ; i++)
        dp[i][0] = i;
    for (int i = 1 ; i <= l2 ; i++)
        dp[0][i] = i;
    for (int i = 1 ; i <= l1 ; i++) {
        for (int j = 1 ; j <= l2 ; j++) {
            if (str1[i - 1] != str2[j - 1])
                dp[i][j] = std::min(std::min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]) + 1;
            else
                dp[i][j] = dp[i - 1][j - 1];
        }
    }
    std::cout << dp[l1][l2];
    return 0;  //Zk...
}
// Created by ZNArk on 2025/11/25.
//