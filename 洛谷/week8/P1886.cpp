//
#include <stdio.h>
#include <iostream>
const int N = 1e6 + 10;
int n,k,ans1[N],ans2[N],a[N],q[N];
void f(int arr[]) {
    int head = 1,tail = 0;
    for (int i = 1 ; i <= n ; i++) {
        while (head <= tail && i - q[head] + 1 > k)
            head++;
        while (head <= tail && a[i] < a[q[tail]])
            tail--;
        q[++tail] = i;
        if (i >= k)
            arr[i - k + 1] = a[q[head]];
    }
}
int main() {
    std::cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
        std::cin >> a[i];
    f(ans1);
    for (int i = 1 ; i <= n ; i++)
        a[i] = -a[i];
    f(ans2);
    for (int i = 1 ; i <= n - k + 1 ; i++)
        std::cout << ans1[i] << " ";
    std::cout << std::endl;
    for (int i = 1 ; i <= n - k + 1 ; i++)
        std::cout << -ans2[i] << " ";
    return 0;  //Zk...
}
// Created by ZNArk on 2025/12/3.
//