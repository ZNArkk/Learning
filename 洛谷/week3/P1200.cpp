//
#include <stdio.h>
#include <iostream>
#include <string>
std::string s1, s2;
int sum1 = 1, sum2 = 1,len1,len2;
int main() {
    std::cin >> s1 >> s2;
    len1 = s1.size();
    len2 = s2.size();
    for (int i = 0 ; i < len1 ; i++)
        sum1 = (sum1 * (s1[i] - 'A' + 1)) % 47;
    for (int i = 0 ; i < len2 ; i++)
        sum2 = (sum2 * (s2[i] - 'A' + 1)) % 47;
    if (sum1 % 47 == sum2 % 47)
        std::cout << "GO" << std::endl;
    else
        std::cout << "STAY" << std::endl;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/27.
//