//
#include <stdio.h>
#include <iostream>
#define LL unsigned long long
using namespace std;
// 最大节点数
const int N = 6e6 + 10;
// tree: 线段树节点值, lazy_tag: 懒标记
LL tree[N],lazy_tag[N];
// n: 数组大小, m: 操作次数, cnt: 节点计数器, root: 根节点编号, left_son/right_son: 左右儿子编号
int n,m,cnt,root,left_son[N],right_son[N];
// 下传懒标记：将当前节点的标记传递给左右儿子
void push_down(int id,int &ls,int &rs,int l,int r) {
    // 动态开点：如果左右儿子不存在则创建
    if (!ls)
        ls = ++cnt;
    if (!rs)
        rs = ++cnt;
    int mid = (l + r) >> 1;
    LL k = lazy_tag[id];
    // 更新左右儿子的值
    tree[ls] += k * (LL)(mid - l + 1);
    tree[rs] += k * (LL)(r - mid);
    // 传递懒标记
    lazy_tag[ls] += k;
    lazy_tag[rs] += k;
    // 清除当前节点的懒标记
    lazy_tag[id] = 0;
}
// 上传信息：用左右儿子的值更新当前节点
void push_up(int id,int &ls,int &rs) {
    if (!ls)
        ls = ++cnt;
    if (!rs)
        rs = ++cnt;
    tree[id] = tree[ls] + tree[rs];
}
// 区间加法：在区间 [l, r] 上加上 k
void add(int &id,int nl,int nr,int l,int r,LL k) {
    // 动态开点：如果当前节点不存在则创建
    if (!id)
        id = ++cnt;
    // 当前区间完全在目标区间内，直接更新
    if (nl >= l && nr <= r) {
        tree[id] += k * (nr - nl + 1);
        lazy_tag[id] += k;
        return;
    }
    // 下传懒标记
    push_down(id,left_son[id],right_son[id],nl,nr);
    int nm = (nl + nr) >> 1;
    // 递归左右儿子
    if (nm >= l)
        add(left_son[id],nl,nm,l,r,k);
    if (nm < r)
        add(right_son[id],nm + 1,nr,l,r,k);
    // 上传信息
    push_up(id,left_son[id],right_son[id]);
}
// 区间查询：查询区间 [l, r] 的和
LL query(int &id,int nl,int nr,int l,int r) {
    // 动态开点
    if (!id)
        id = ++cnt;
    // 当前区间完全在目标区间内，直接返回
    if (nl >= l && nr <= r)
        return tree[id];
    // 下传懒标记
    push_down(id,left_son[id],right_son[id],nl,nr);
    LL sum = 0;
    int nm = (nl + nr) >> 1;
    // 递归查询左右儿子
    if (nm >= l)
        sum += query(left_son[id],nl,nm,l,r);
    if (nm < r)
        sum += query(right_son[id],nm + 1,nr,l,r);
    return sum;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    // 处理 m 次操作
    for (int i = 1 ; i <= m ; i++) {
        LL type,l,r;
        LL k;
        cin >> type >> l >> r;
        // type=1: 区间加法
        if (type == 1) {
            cin >> k;
            add(root,1,n,l,r,k);
        }
        // type=2: 区间查询（加上初始值 1+2+...+n）
        else
            cout << query(root,1,n,l,r) + (l + r) * (r - l + 1) / 2 << endl;
    }
    return 0;  //Zk...
}
// Created by ZNArk on 2026/1/3.
//