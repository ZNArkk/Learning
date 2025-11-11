//
#include <stdio.h>
#include <iostream>
int n,k,m;
struct node {
    int pre,next,id;
}a[105];
using namespace std;
int main() {
    cin >> n >> m;
    int tot = m;
    a[1].pre = n;
    a[1].next = 2;
    a[1].id = 1;
    for (int i = 2 ; i <= n ; i++) {
        a[i].id = i;
        a[i].pre = i - 1;
        a[i].next = i + 1;
    }
    a[n].next = 1;
    int i;
    for (i = 1 ; a[i].pre != a[i].id ; i = a[i].next) {
        tot--;
        if (!tot) {
            tot = m;
            std::cout << a[i].id << " ";
            a[a[i].pre].next = a[i].next;
            a[a[i].next].pre = a[i].pre;
        }
    }
    std::cout << a[i].id << std::endl;
    return 0;  //Zk...
}

// Created by ZNArk on 2025/11/11.
//