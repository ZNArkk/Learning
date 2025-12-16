//
#include <stdio.h>
#include <iostream>
#define LL long long
const int N = 1e5 + 10;
struct node {
    LL num,left,right,lazy_t1,lazy_t2;
}tree[N << 2];
LL n,q,m,a[N];
inline LL left_son(LL x) {
    return x << 1;
}
inline LL right_son(LL x) {
    return x << 1 | 1;
}
void push_up(LL id) {
    LL ls = left_son(id);
    LL rs = right_son(id);
    tree[id].num = (tree[ls].num + tree[rs].num) % m;
}
void push_down(LL id) {
    LL ls = left_son(id);
    LL rs = right_son(id);
    LL l = tree[id].left,r = tree[id].right;
    LL t1 = tree[id].lazy_t1,t2 = tree[id].lazy_t2;
    LL mid = (l + r) >> 1;
    tree[ls].num = tree[ls].num * t1 % m;
    tree[ls].num = (tree[ls].num + t2 * (mid - l + 1)) % m;
    tree[ls].lazy_t1 = tree[ls].lazy_t1 * t1 % m;
    tree[ls].lazy_t2 = (tree[ls].lazy_t2 * t1 + t2) % m;
    tree[rs].num = tree[rs].num * t1 % m;
    tree[rs].num = (tree[rs].num + t2 * (r - mid)) % m;
    tree[rs].lazy_t1 = tree[rs].lazy_t1 * t1 % m;
    tree[rs].lazy_t2 = (tree[rs].lazy_t2 * t1 + t2) % m;
    tree[id].lazy_t1 = 1;
    tree[id].lazy_t2 = 0;
}
void build(LL id,LL l,LL r) {
    tree[id].left = l;
    tree[id].right = r;
    tree[id].lazy_t1 = 1;
    if (l == r) {
        tree[id].num = a[l] % m;
        return;
    }
    LL mid = (l + r) >> 1;
    build(left_son(id),l,mid);
    build(right_son(id),mid + 1,r);
    push_up(id);
}
void update(int type,LL id,LL l,LL r,LL k) {
    LL nl = tree[id].left;
    LL nr = tree[id].right;
    if (nl >= l && nr <= r) {
        if (type == 1) {
            tree[id].lazy_t1 = tree[id].lazy_t1 * k % m;
            tree[id].lazy_t2 = tree[id].lazy_t2 * k % m;
            tree[id].num = tree[id].num * k % m;
        }
        else {
            tree[id].lazy_t2 = (tree[id].lazy_t2 + k) % m;
            tree[id].num = (tree[id].num + k * (nr - nl + 1)) % m;
        }
        return;
    }
    push_down(id);
    LL nm = (nl + nr) >> 1;
    if (l <= nm)
        update(type,left_son(id),l,r,k);
    if (r > nm)
        update(type,right_son(id),l,r,k);
    push_up(id);
}
inline LL query(LL id,LL l,LL r) {
    LL sum = 0;
    LL nl = tree[id].left;
    LL nr = tree[id].right;
    if (nl >= l && nr <= r)
        return tree[id].num % m;
    push_down(id);
    LL nm = (nl + nr) >> 1;
    if (l <= nm)
        sum = (sum + query(left_son(id),l,r)) % m;
    if (r > nm)
        sum = (sum + query(right_son(id),l,r)) % m;
    return sum;
}
int main() {
    std::cin >> n >> q >> m;
    for (int i = 1 ; i <= n ; i++)
        std::cin >> a[i];
    build(1,1,n);
    for (int i = 1 ; i <= q ; i++) {
        int type;
        LL x,y,k;
        std::cin >> type;
        if (type == 1) {
            std::cin >> x >> y >> k;
            update(1,1,x,y,k);
        }
        else if (type == 2) {
            std::cin >> x >> y >> k;
            update(2,1,x,y,k);
        }
        else {
            std::cin >> x >> y;
            std::cout << query(1,x,y) << std::endl;
        }
    }
    return 0;  //Zk...
}
// Created by ZNArk on 2025/12/11.
//