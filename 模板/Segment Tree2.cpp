//
#include <stdio.h>
#include <iostream>
#define LL long long
// 最大数组大小
const int N = 1e5 + 10;
// 线段树节点：num为区间和，left/right为区间范围，lazy_t1为乘法标记，lazy_t2为加法标记
struct node {
    LL num,left,right,lazy_t1,lazy_t2;
}tree[N << 2];
// n: 数组大小, q: 操作次数, m: 模数, a: 原数组
LL n,q,m,a[N];
// 获取左儿子编号
inline LL left_son(LL x) {
    return x << 1;
}
// 获取右儿子编号
inline LL right_son(LL x) {
    return x << 1 | 1;
}
// 上传信息：用左右儿子的值更新当前节点
void push_up(LL id) {
    LL ls = left_son(id);
    LL rs = right_son(id);
    tree[id].num = (tree[ls].num + tree[rs].num) % m;
}
// 下传懒标记：先乘后加的顺序传递标记
void push_down(LL id) {
    LL ls = left_son(id);
    LL rs = right_son(id);
    LL l = tree[id].left,r = tree[id].right;
    LL t1 = tree[id].lazy_t1,t2 = tree[id].lazy_t2;
    LL mid = (l + r) >> 1;
    // 更新左儿子：先乘后加
    tree[ls].num = tree[ls].num * t1 % m;
    tree[ls].num = (tree[ls].num + t2 * (mid - l + 1)) % m;
    tree[ls].lazy_t1 = tree[ls].lazy_t1 * t1 % m;
    tree[ls].lazy_t2 = (tree[ls].lazy_t2 * t1 + t2) % m;
    // 更新右儿子：先乘后加
    tree[rs].num = tree[rs].num * t1 % m;
    tree[rs].num = (tree[rs].num + t2 * (r - mid)) % m;
    tree[rs].lazy_t1 = tree[rs].lazy_t1 * t1 % m;
    tree[rs].lazy_t2 = (tree[rs].lazy_t2 * t1 + t2) % m;
    // 清除当前节点的懒标记（乘法标记初始为1，加法标记初始为0）
    tree[id].lazy_t1 = 1;
    tree[id].lazy_t2 = 0;
}
// 建树：在节点 id 处建立区间 [l, r] 的线段树
void build(LL id,LL l,LL r) {
    tree[id].left = l;
    tree[id].right = r;
    tree[id].lazy_t1 = 1;
    // 叶子节点
    if (l == r) {
        tree[id].num = a[l] % m;
        return;
    }
    LL mid = (l + r) >> 1;
    // 递归建树
    build(left_son(id),l,mid);
    build(right_son(id),mid + 1,r);
    push_up(id);
}
// 区间更新：type=1为乘法，type=2为加法，在区间 [l, r] 上操作 k
void update(int type,LL id,LL l,LL r,LL k) {
    LL nl = tree[id].left;
    LL nr = tree[id].right;
    // 当前区间完全在目标区间内，直接更新
    if (nl >= l && nr <= r) {
        if (type == 1) {
            // 乘法：更新标记和值
            tree[id].lazy_t1 = tree[id].lazy_t1 * k % m;
            tree[id].lazy_t2 = tree[id].lazy_t2 * k % m;
            tree[id].num = tree[id].num * k % m;
        }
        else {
            // 加法：更新标记和值
            tree[id].lazy_t2 = (tree[id].lazy_t2 + k) % m;
            tree[id].num = (tree[id].num + k * (nr - nl + 1)) % m;
        }
        return;
    }
    // 下传懒标记
    push_down(id);
    LL nm = (nl + nr) >> 1;
    // 递归左右儿子
    if (l <= nm)
        update(type,left_son(id),l,r,k);
    if (r > nm)
        update(type,right_son(id),l,r,k);
    // 上传信息
    push_up(id);
}
// 区间查询：查询区间 [l, r] 的和
inline LL query(LL id,LL l,LL r) {
    LL sum = 0;
    LL nl = tree[id].left;
    LL nr = tree[id].right;
    // 当前区间完全在目标区间内，直接返回
    if (nl >= l && nr <= r)
        return tree[id].num % m;
    // 下传懒标记
    push_down(id);
    LL nm = (nl + nr) >> 1;
    // 递归查询左右儿子
    if (l <= nm)
        sum = (sum + query(left_son(id),l,r)) % m;
    if (r > nm)
        sum = (sum + query(right_son(id),l,r)) % m;
    return sum;
}
int main() {
    std::cin >> n >> q >> m;
    // 读入原数组
    for (int i = 1 ; i <= n ; i++)
        std::cin >> a[i];
    // 建立线段树
    build(1,1,n);
    // 处理 q 次操作
    for (int i = 1 ; i <= q ; i++) {
        int type;
        LL x,y,k;
        std::cin >> type;
        // type=1: 区间乘法
        if (type == 1) {
            std::cin >> x >> y >> k;
            update(1,1,x,y,k);
        }
        // type=2: 区间加法
        else if (type == 2) {
            std::cin >> x >> y >> k;
            update(2,1,x,y,k);
        }
        // type=3: 区间查询
        else {
            std::cin >> x >> y;
            std::cout << query(1,x,y) << std::endl;
        }
    }
    return 0;  //Zk...
}
// Created by ZNArk on 2025/12/11.
//