//
#include <stdio.h>
#include <iostream>
double a,b,c,d;
double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}
int main() {
    std::cin >> a >> b >> c >> d;
    for (double i = -100 ; i < 100 ; i++) {
        if (f(i) * f(i + 1) < 0) {
            double l = i;
            double r = i + 1;
            while (l < r - 0.01) {
                double mid = (l + r) / 2;
                if (f(l) * f(mid) < 0)
                    r = mid;
                else
                    l = mid;
            }
            printf("%.2lf ",(l + r) / 2);
        }
        if (f(i) == 0) printf("%.2lf ",i);
    }
    if (f(100) == 0) printf("%.2lf\n",100);
    return 0;  //Zk...
}

// Created by ZNArk on 2025/11/4.
//