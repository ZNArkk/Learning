//
#include <filesystem>
#include <stdio.h>
#include <iostream>
int n,a[1005],b[1005];
void swap(int &a,int &b) {
    int t;
    t = a;
    a = b;
    b = t;
}
int f(int x) {
    if (x < 0)
        return -x;
    return x;
}
int main() {
    std::cin >> n;
    for (int i = 1 ; i <= n ; i++)
        std::cin >> a[i];
    for (int i = 1 ; i < n ; i++)
        b[i] = f(a[i] - a[i + 1]);
    for (int i = 1 ; i < n ; i++) {
        for (int j = 1 ; j < n - i ; j++) {
            if (b[j] > b[j + 1])
                swap(b[j], b[j + 1]);
        }
    }
    for (int i = 1 ; i < n ; i++) {
        if (b[i] != i) {
            std::cout << "Not jolly" << std::endl;
            return 0;
        }
    }
    std::cout << "Jolly" << std::endl;
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/27.
//