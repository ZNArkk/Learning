//
#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
std::string a;
int t;
int main() {
    std::cin >> t;
    while (t--) {
        std::cin >> a;
        std::stack<char> st;
        for (int i = 0 ; i < a.size() ; i++) {
            if (st.empty()) {
                st.push(a[i]);
                continue;
            }
            if ((st.top() == '(' && a[i] == ')') || (st.top() == '[' && a[i] == ']') || (st.top() == '{' && a[i] == '}'))
                st.pop();
            else
                st.push(a[i]);
        }
        if (st.empty())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;  //Zk...
}
// Created by ZNArk on 2025/11/19.
