/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-20 12:14:28
 |File Name: Multiply_and_Add_zjut1101.cpp
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
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
const int maxn = 100005;
const int mod = 1000000007;
struct Tree{
    ll sum;
    int l,r;
    ll add,mul;
}tree[maxn << 2];
char op[10];
int n,m;
int a,b;
ll c;
void pushup(int rt) {
    tree[rt].sum = tree[L(rt)].sum + tree[R(rt)].sum;
    tree[rt].sum %= mod;
}
void pushdown(int rt) {
    if(tree[rt].add != 0 || tree[rt].mul != 1){
        tree[L(rt)].sum = tree[L(rt)].sum * tree[rt].mul + tree[rt].add*(tree[L(rt)].r - tree[L(rt)].l + 1);
        tree[L(rt)].sum %= mod;
        tree[L(rt)].mul *= tree[rt].mul;
        tree[L(rt)].mul %= mod;
        tree[L(rt)].add = tree[L(rt)].add * tree[rt].mul + tree[rt].add;
        tree[L(rt)].add %= mod;
        tree[R(rt)].sum = tree[R(rt)].sum * tree[rt].mul + tree[rt].add*(tree[R(rt)].r - tree[R(rt)].l + 1);
        tree[R(rt)].sum %= mod;
        tree[R(rt)].mul *= tree[rt].mul;
        tree[R(rt)].mul %= mod;
        tree[R(rt)].add = tree[R(rt)].add * tree[rt].mul + tree[rt].add;
        tree[R(rt)].add %= mod;
        tree[rt].add = 0;
        tree[rt].mul = 1;
    }
}
void build(int l,int r,int rt) {
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].add = 0;
    tree[rt].mul = 1;
    tree[rt].sum = l;
    if(l == r) {
        return ;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    build(l,mid,L(rt));
    build(mid + 1, r, R(rt));
    tree[rt].sum = tree[L(rt)].sum + tree[R(rt)].sum;
    tree[rt].sum %= mod;
}
void add(int l,int r,ll v,int rt) {
    if(l <= tree[rt].l && r >= tree[rt].r) {
        tree[rt].add += v;
        tree[rt].add %= mod;
        tree[rt].sum += v*(tree[rt].r - tree[rt].l + 1);
        tree[rt].sum %= mod;
        return ;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= r) {
        add(l,r,v,L(rt));
    } else if(l >= mid + 1) {
        add(l,r,v,R(rt));
    } else {
        add(l,mid,v,L(rt));
        add(mid+1,r,v,R(rt));
    }
    pushup(rt);
}
void mul(int l,int r,ll v,int rt) {
    if(l <= tree[rt].l && r >= tree[rt].r) {
        tree[rt].mul *= v;
        tree[rt].mul %= mod;
        tree[rt].add *= v;
        tree[rt].add %= mod;
        tree[rt].sum *= v;
        tree[rt].sum %= mod;
        return ;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= r) {
        mul(l,r,v,L(rt));
    } else if(l >= mid + 1) {
        mul(l,r,v,R(rt));
    } else {
        mul(l,mid,v,L(rt));
        mul(mid + 1, r, v, R(rt));
    }
    pushup(rt);
} 
ll query(int l,int r,int rt) {
    ll sum = 0;
    if(l <= tree[rt].l && r >= tree[rt].r) {
        return tree[rt].sum % mod;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= r) {
        return query(l,r,L(rt)) % mod;
    } else if(l >= mid + 1) {
        return query(l,r,R(rt)) % mod;
    } else {
        sum += query(l,mid,L(rt));
        sum += query(mid+1,r,R(rt));
        return sum % mod;
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d %d",&n,&m) != EOF) {
        build(0,n,1);
        while(m --) {
            scanf("%s",op);
            if(op[0] == 'a') {
                scanf("%d %d %lld",&a,&b,&c);
                add(a,b,c,1);
            } else if(op[0] == 'm') {
                scanf("%d %d %lld",&a,&b,&c);
                mul(a,b,c,1);
            } else {
                scanf("%d %d",&a,&b);
                printf("%lld\n",query(a,b,1));
            }
        }
        puts("");
    }
	return 0;
}

