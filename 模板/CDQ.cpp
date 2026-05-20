//
#include <stdio.h>
#include <iostream>
// 最大节点数
const int N = 2e6 + 10;
// CDQ分治节点：type=1更新，type=2左查询，type=3右查询
struct node {
    int type,location,value;
}a[N],b[N];
// n: 初始数组大小, m: 操作次数, id/p/q: 操作参数, ans: 查询答案数组, tot1/tot2: 计数器
int n,m,id,p,q,ans[N],tot1,tot2;
// 处理查询：根据操作类型更新答案
void check(int x,int sum) {
    if (a[x].type == 2)
        ans[a[x].value] -= sum;
    else if (a[x].type == 3)
        ans[a[x].value] += sum;
}
// CDQ分治主函数：离线处理三维偏序问题
void CDQ(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    // 分治左右区间
    CDQ(l, mid);
    CDQ(mid + 1, r);
    // 归并过程：统计左区间对右区间的贡献
    int sum = 0;
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        // 按位置排序
        if (a[i].location <= a[j].location) {
            // 左区间的更新操作：累加值
            if (a[i].type == 1)
                sum += a[i].value;
            b[++k] = a[i++];
        }
        else {
            // 右区间的查询操作：计算贡献
            check(j,sum);
            b[++k] = a[j++];
        }
    }
    // 处理剩余元素
    while (i <= mid)
        b[++k] = a[i++];
    while (j <= r) {
        check(j,sum);
        b[++k] = a[j++];
    }
    // 复制回原数组
    for (i = l,j = 1 ; i <= r ; i++) a[i] = b[j++];
}
int main() {
    std::cin >> n >> m;
    // 初始化：将初始数组元素作为更新操作
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> a[i].value;
        a[i].location = i;
        a[i].type = 1;
    }
    tot1 = n;
    // 处理 m 次操作
    for (int i = 1 ; i <= m ; i++) {
        std::cin >> id >> p >> q;
        // id=1: 单点更新操作
        if (id == 1) {
            a[++tot1].location = p;
            a[tot1].value = q;
            a[tot1].type = 1;
        }
        // id=2: 区间查询，拆分为两个查询 [1,p-1] 和 [1,q]
        else {
            a[++tot1].location = p - 1;
            a[tot1].value = ++tot2;
            a[tot1].type = 2;
            a[++tot1].location = q;
            a[tot1].value = tot2;
            a[tot1].type = 3;
        }
    }
    // 执行CDQ分治
    CDQ(1,tot1);
    // 输出所有查询答案
    for (int i = 1 ; i <= tot2 ; i++)
        std::cout << ans[i] << '\n';
    return 0;  //Zk...
}
// Created by ZNArk on 2025/10/15.
//