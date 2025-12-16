//
#include <stdio.h>
#include <iostream>
#define LL long long
const int N = 1e5 + 10;
struct node {
    LL left,right,num,lazy_tag;
}tree[N << 2];
LL n,m,a[N];
LL left_son(LL x) {
    return x << 1;
}
LL right_son(LL x) {
    return x << 1 | 1;
}
void push_up(LL x) {
    tree[x].num = tree[left_son(x)].num + tree[right_son(x)].num;
}
void build(LL id,LL l,LL r) {
    tree[id].left = l;
    tree[id].right = r;
    if (l == r) {
        tree[id].num = a[l];
        return;
    }
    LL mid = (l + r) >> 1;
    build(left_son(id),l,mid);
    build(right_son(id),mid + 1,r);
    push_up(id);
}
void push_down(LL x) {
    LL mid = (tree[x].left + tree[x].right) >> 1;
    LL k = tree[x].lazy_tag,l = left_son(x),r = right_son(x);
    tree[l].lazy_tag += k;
    tree[r].lazy_tag += k;
    tree[l].num += k * (tree[l].right - tree[x].left + 1);
    tree[r].num += k * (tree[x].right - tree[r].left + 1);
    tree[x].lazy_tag = 0;
}
void add(LL id,LL l,LL r,LL k) {
    LL nl = tree[id].left;
    LL nr = tree[id].right;
    if (nl >= l && nr <= r) {
        tree[id].num += k * (nr - nl + 1);
        tree[id].lazy_tag += k;
        return;
    }
    push_down(id);
    LL nm = tree[left_son(id)].right;
    if (l <= nm)
        add(left_son(id),l,r,k);
    if (nm < r)
        add(right_son(id),l,r,k);
    push_up(id);
}
LL query(LL id,LL l,LL r) {
    LL sum = 0;
    LL nl = tree[id].left;
    LL nr = tree[id].right;
    if (nl >= l && nr <= r)
        return tree[id].num;
    if (nl > r || nr < l)
        return 0;
    push_down(id);
    LL nm = tree[left_son(id)].right;
    if (l <= nm)
        sum += query(left_son(id),l,r);
    if (nm < r)
        sum += query(right_son(id),l,r);
    return sum;
}
int main() {
    std::cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        std::cin >> a[i];
    build(1,1,n);
    for (int i = 1 ; i <= m ; i++) {
        LL type,x,y;
        LL k;
        std::cin >> type;
        if (type == 1) {
            std::cin >> x >> y >> k;
            add(1,x,y,k);
        }
        else {
            std::cin >> x >> y;
            std::cout << query(1,x,y) << std::endl;
        }
    }
    return 0;  //Zk...
}
// Created by ZNArk on 2025/12/10.
//