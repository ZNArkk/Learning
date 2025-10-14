//
#include <stdio.h>
#include <iostream>
const int N = 2e6 + 10;
struct node {
    int type,location,value;
}a[N],b[N];
int n,m,id,p,q,ans[N],tot1,tot2;
void check(int x,int sum) {
    if (a[x].type == 2)
        ans[a[x].value] -= sum;
    else if (a[x].type == 3)
        ans[a[x].value] += sum;
}
void CDQ(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    CDQ(l, mid);
    CDQ(mid + 1, r);
    int sum = 0;
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i].location <= a[j].location) {
            if (a[i].type == 1)
                sum += a[i].value;
            b[++k] = a[i++];
        }
        else {
            check(j,sum);
            b[++k] = a[j++];
        }
    }
    while (i <= mid)
        b[++k] = a[i++];
    while (j <= r) {
        check(j,sum);
        b[++k] = a[j++];
    }
    for (i = l,j = 1 ; i <= r ; i++) a[i] = b[j++];
}
int main() {
    std::cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> a[i].value;
        a[i].location = i;
        a[i].type = 1;
    }
    tot1 = n;
    for (int i = 1 ; i <= m ; i++) {
        std::cin >> id >> p >> q;
        if (id == 1) {
            a[++tot1].location = p;
            a[tot1].value = q;
            a[tot1].type = 1;
        }
        else {
            a[++tot1].location = p - 1;
            a[tot1].value = ++tot2;
            a[tot1].type = 2;
            a[++tot1].location = q;
            a[tot1].value = tot2;
            a[tot1].type = 3;
        }
    }
    CDQ(1,tot1);
    for (int i = 1 ; i <= tot2 ; i++)
        std::cout << ans[i] << '\n';
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/15.
//