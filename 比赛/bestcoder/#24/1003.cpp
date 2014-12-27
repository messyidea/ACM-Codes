/***********************************************\
  |Author: YMC
  |Created Time: 2014/12/27 19:05:48
  |File Name: a.cpp
  |Description: 
  \***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
#define mod 2333333
struct Tree{
    int l,r;
    int x;
    int add;
}tree[50005<<2];
int n,m;
int da[50005];
ll mod_pow(ll x,ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
void pushup(int rt) {
    tree[rt].x = (tree[L(rt)].x + tree[R(rt)].x)%mod;
}
void build(int rt,int l,int r) {
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].add = -1;
    if(l == r) {
        tree[rt].x = da[l];
        tree[rt].x %= mod;
        return ;
    }
    int mid = l + r >> 1;
    build(L(rt),l,mid);
    build(R(rt),mid + 1,r);
    pushup(rt);
}
void pushdown(int rt) {
    if(tree[rt].add != -1) {
        tree[L(rt)].add += tree[rt].add;
        tree[R(rt)].add += tree[rt].add;
        tree[L(rt)].x += (tree[L(rt)].r - tree[L(rt)].l + 1) * tree[rt].x;
        tree[R(rt)].x += (tree[R(rt)].r - tree[R(rt)].l + 1) * tree[rt].x;
        tree[rt].x %= mod;
        tree[L(rt)].x %= mod;
        tree[R(rt)].x %= mod;
        tree[rt].add = -1;
    }
}
int query(int rt,int l,int r) {
    if(tree[rt].l == l && tree[rt].r == r) {
        return tree[rt].x;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    int sum = 0;
    if(r <= mid) {
        return query(L(rt),l,r) % mod;
    } else if(l >= mid + 1) {
        return query(R(rt),l,r) % mod;
    } else {
        sum += query(L(rt),l,mid);
        sum += query(R(rt),mid + 1,r);
        sum %= mod;
        return sum;
    }
}

void update(int rt,int x) {
    if(tree[rt].l == x && tree[rt].r == x) {
        tree[rt].x = mod_pow(2,tree[rt].x);
        return ;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(x <= mid) update(L(rt),x);
    else update(R(rt),x);
    pushup(rt);
}
void u2(int rt,int l,int r,int v) {
    if(tree[rt].l == l && tree[rt].r == r) {
        tree[rt].x += (tree[rt].r - tree[rt].l + 1) * v;
        tree[rt].add += v;
        return ;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(r <= mid) u2(L(rt),l,r,v);
    else if(l >= mid + 1) u2(R(rt),l,r,v);
    else {
        u2(L(rt),l,mid,v);
        u2(R(rt),mid + 1, r, v);
    }
    pushup(rt);
}
int main() {
    //freopen("input.txt","r",stdin); 
    int opt;
    int l,r,v;
    while(scanf("%d %d",&n,&m)!=EOF) {
        srep(i,n) {
            scanf("%d",&da[i]);
        }
        build(1,1,n);
        while(m --) {
            scanf("%d",&opt);
            if(opt == 1) {
                scanf("%d %d",&l,&r);
                printf("%d\n",query(1,l,r));
            } else if(opt == 2) {
                scanf("%d",&l);
                update(1,l);
            } else {
                scanf("%d %d %d",&l,&r,&v);
                u2(1,l,r,v);
            }
        }
    }
    return 0;
}

