//
//
#include <stdio.h>
#include <iostream>
int m,s,t,tt,ss;
int main() {
    std::cin >> m >> s >> t;
    tt = t;
    ss = s;
    while (s > 0 && t > 0) {
        int k = (13 - m) / 4;
        if (m >= 10) {
            s -= 60;
            t--;
            m -= 10;
        }
        else if (m >= 2 && t >= k + 1 && s >= 17 * (k + 1)) {
            s -= 60;
            t -= k + 1;
            m += 4 * k - 10;
        }
        else if (s >= 120 && t >= 7) {
            s -= 120;
            t -= 7;
        }
        else {
            s -= 17;
            t--;
        }
    }
    if (s < 0)
        std::cout << "Yes" << std::endl << tt - t;
    else
        std::cout << "No" << std::endl << ss - s;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/11/4.
//