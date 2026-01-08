//
#include <stdio.h>
#include <iostream>
#define LL unsigned long long
using namespace std;
const int N = 6e6 + 10;
LL tree[N],lazy_tag[N];
int n,m,cnt,root,left_son[N],right_son[N];
void push_down(int id,int &ls,int &rs,int l,int r) {
    if (!ls)
        ls = ++cnt;
    if (!rs)
        rs = ++cnt;
    int mid = (l + r) >> 1;
    LL k = lazy_tag[id];
    tree[ls] += k * (LL)(mid - l + 1);
    tree[rs] += k * (LL)(r - mid);
    lazy_tag[ls] += k;
    lazy_tag[rs] += k;
    lazy_tag[id] = 0;
}
void push_up(int id,int &ls,int &rs) {
    if (!ls)
        ls = ++cnt;
    if (!rs)
        rs = ++cnt;
    tree[id] = tree[ls] + tree[rs];
}
void add(int &id,int nl,int nr,int l,int r,LL k) {
    if (!id)
        id = ++cnt;
    if (nl >= l && nr <= r) {
        tree[id] += k * (nr - nl + 1);
        lazy_tag[id] += k;
        return;
    }
    push_down(id,left_son[id],right_son[id],nl,nr);
    int nm = (nl + nr) >> 1;
    if (nm >= l)
        add(left_son[id],nl,nm,l,r,k);
    if (nm < r)
        add(right_son[id],nm + 1,nr,l,r,k);
    push_up(id,left_son[id],right_son[id]);
}
LL query(int &id,int nl,int nr,int l,int r) {
    if (!id)
        id = ++cnt;
    if (nl >= l && nr <= r)
        return tree[id];
    push_down(id,left_son[id],right_son[id],nl,nr);
    LL sum = 0;
    int nm = (nl + nr) >> 1;
    if (nm >= l)
        sum += query(left_son[id],nl,nm,l,r);
    if (nm < r)
        sum += query(right_son[id],nm + 1,nr,l,r);
    return sum;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        LL type,l,r;
        LL k;
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> k;
            add(root,1,n,l,r,k);
        }
        else
            cout << query(root,1,n,l,r) + (l + r) * (r - l + 1) / 2 << endl;
    }
    return 0;  //Zk...
}
// Created by ZNArk on 2026/1/3.
//