/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-30 12:57:31
 |File Name: Calculate_numbers.cpp
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
const int maxn = 10005;
int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a%b);
}
struct Tree {
    int l,r,g,s,c;
}tree[maxn << 2];
void pushup(int rt) {
    tree[rt].s = tree[L(rt)].s + tree[R(rt)].s;
    tree[rt].g = gcd(tree[L(rt)].g,tree[R(rt)].g);
}
void build(int l,int r,int rt) {
    tree[rt].l = l; tree[rt].r = r;
    tree[rt].c = -1;
    if(l == r) {
        scanf("%d",&tree[rt].s);
        tree[rt].g = tree[rt].s;
        return ;
    }
    int mid = l + r >> 1;
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
    pushup(rt);
}
void pushdown(int rt) {
    if(tree[rt].c == 1) {
        tree[L(rt)].c = 1; tree[R(rt)].c = 1;
        tree[L(rt)].s = tree[rt].g * (tree[L(rt)].r - tree[L(rt)].l + 1);
        tree[R(rt)].s = tree[rt].g * (tree[R(rt)].r - tree[R(rt)].l + 1);
        tree[L(rt)].g = tree[rt].g;
        tree[R(rt)].g = tree[rt].g;
        tree[rt].c = -1;
    }
}
void update(int l,int r,int c,int rt) {
    if(l <= tree[rt].l && r >= tree[rt].r) {
        tree[rt].c = 1;
        tree[rt].s = c * (tree[rt].r - tree[rt].l + 1);
        tree[rt].g = c;
        return ; 
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= r) update(l,r,c,L(rt));
    else if(l >= mid + 1) update(l,r,c,R(rt));
    else {
        update(l,mid,c,L(rt));
        update(mid + 1,r,c,R(rt));
    }
    pushup(rt);
}
int qgcd(int l,int r,int rt ) {
    if(l <= tree[rt].l && r >= tree[rt].r) {
        return tree[rt].g;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= r) return qgcd(l,r,L(rt));
    else if(l >= mid + 1) return qgcd(l,r,R(rt));
    else {
        return gcd(qgcd(l,mid,L(rt)),qgcd(mid+1,r,R(rt)));
    }
}
int qsum(int l,int r,int rt ) {
    if(l <= tree[rt].l && r >= tree[rt].r) {
        return tree[rt].s;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= r) return qsum(l,r,L(rt));
    else if(l >= mid + 1) return qsum(l,r,R(rt));
    else {
        return (qsum(l,mid,L(rt))+qsum(mid+1,r,R(rt)));
    }
}
int n,m;
char op[15];
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int a,b,c;
    while(T--) {
        scanf("%d %d",&n,&m);
        build(1,n,1);
        rep(i,m) {
            scanf("%s",op);
            if(op[0] == 'G') {
                scanf("%d %d",&a,&b);
                printf("GCD %d\n",qgcd(a,b,1));
            } else if(op[0] == 'S' && op[1] == 'U') {
                scanf("%d %d",&a,&b);
                printf("SUM %d\n",qsum(a,b,1));
            } else {
                scanf("%d %d %d",&a,&b,&c);
                update(a,b,c,1);
            }
        }
    }
	return 0;
}

