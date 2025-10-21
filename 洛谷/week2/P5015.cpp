//
#include <iostream>
#include <string>
std::string s;
int ans;
int main()
{
    while(std::cin >> s)
        ans += s.size();
    std::cout << ans;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/21.
