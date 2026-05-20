//
#include <stdio.h>
#include <iostream>
#define LL long long
// 最大数组大小
const int N = 1e5 + 10;
// 线段树节点：left/right为区间范围，num为区间和，lazy_tag为懒标记
struct node {
    LL left,right,num,lazy_tag;
}tree[N << 2];
// n: 数组大小, m: 操作次数, a: 原数组
LL n,m,a[N];
// 获取左儿子编号
LL left_son(LL x) {
    return x << 1;
}
// 获取右儿子编号
LL right_son(LL x) {
    return x << 1 | 1;
}
// 上传信息：用左右儿子的值更新当前节点
void push_up(LL x) {
    tree[x].num = tree[left_son(x)].num + tree[right_son(x)].num;
}
// 建树：在节点 id 处建立区间 [l, r] 的线段树
void build(LL id,LL l,LL r) {
    tree[id].left = l;
    tree[id].right = r;
    // 叶子节点
    if (l == r) {
        tree[id].num = a[l];
        return;
    }
    LL mid = (l + r) >> 1;
    // 递归建树
    build(left_son(id),l,mid);
    build(right_son(id),mid + 1,r);
    push_up(id);
}
// 下传懒标记：将当前节点的标记传递给左右儿子
void push_down(LL x) {
    LL mid = (tree[x].left + tree[x].right) >> 1;
    LL k = tree[x].lazy_tag,l = left_son(x),r = right_son(x);
    // 传递懒标记
    tree[l].lazy_tag += k;
    tree[r].lazy_tag += k;
    // 更新左右儿子的值
    tree[l].num += k * (tree[l].right - tree[x].left + 1);
    tree[r].num += k * (tree[x].right - tree[r].left + 1);
    // 清除当前节点的懒标记
    tree[x].lazy_tag = 0;
}
// 区间加法：在区间 [l, r] 上加上 k
void add(LL id,LL l,LL r,LL k) {
    LL nl = tree[id].left;
    LL nr = tree[id].right;
    // 当前区间完全在目标区间内，直接更新
    if (nl >= l && nr <= r) {
        tree[id].num += k * (nr - nl + 1);
        tree[id].lazy_tag += k;
        return;
    }
    // 下传懒标记
    push_down(id);
    LL nm = tree[left_son(id)].right;
    // 递归左右儿子
    if (l <= nm)
        add(left_son(id),l,r,k);
    if (nm < r)
        add(right_son(id),l,r,k);
    // 上传信息
    push_up(id);
}
// 区间查询：查询区间 [l, r] 的和
LL query(LL id,LL l,LL r) {
    LL sum = 0;
    LL nl = tree[id].left;
    LL nr = tree[id].right;
    // 当前区间完全在目标区间内，直接返回
    if (nl >= l && nr <= r)
        return tree[id].num;
    // 当前区间与目标区间无交集，返回0
    if (nl > r || nr < l)
        return 0;
    // 下传懒标记
    push_down(id);
    LL nm = tree[left_son(id)].right;
    // 递归查询左右儿子
    if (l <= nm)
        sum += query(left_son(id),l,r);
    if (nm < r)
        sum += query(right_son(id),l,r);
    return sum;
}
int main() {
    std::cin >> n >> m;
    // 读入原数组
    for (int i = 1 ; i <= n ; i++)
        std::cin >> a[i];
    // 建立线段树
    build(1,1,n);
    // 处理 m 次操作
    for (int i = 1 ; i <= m ; i++) {
        LL type,x,y;
        LL k;
        std::cin >> type;
        // type=1: 区间加法
        if (type == 1) {
            std::cin >> x >> y >> k;
            add(1,x,y,k);
        }
        // type=2: 区间查询
        else {
            std::cin >> x >> y;
            std::cout << query(1,x,y) << std::endl;
        }
    }
    return 0;  //Zk...
}
// Created by ZNArk on 2025/12/10.
//