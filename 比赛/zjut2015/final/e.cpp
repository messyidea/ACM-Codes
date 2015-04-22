/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/22 22:08:24
 |File Name: e_accept.cpp
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
int n,m;
struct Tree{
    int l,r;
    int d,f;
    ll sum;
}tree[100005<<2];
void build(int l,int r,int rt) {
    tree[rt].l = l; tree[rt].r = r;
    tree[rt].d = 0;
    tree[rt].f = 0;
    tree[rt].sum = 0;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
}
int op;
int a,b,c;
void pushdown(int rt) {
    if(tree[rt].d != 0) {
        tree[L(rt)].f += tree[rt].f;
        tree[L(rt)].d += tree[rt].d;
        tree[L(rt)].sum += (ll)(tree[rt].f*2 + (tree[L(rt)].r - tree[L(rt)].l)*tree[rt].d) * (ll)(tree[L(rt)].r - tree[L(rt)].l + 1) / 2;
        tree[R(rt)].f += tree[rt].f + (tree[L(rt)].r - tree[L(rt)].l + 1) * tree[rt].d;
        tree[R(rt)].d += tree[rt].d;
        tree[R(rt)].sum += (ll)((tree[rt].f + (tree[L(rt)].r - tree[L(rt)].l + 1) * tree[rt].d)*2 + (tree[R(rt)].r - tree[R(rt)].l)*tree[rt].d) * (ll)(tree[R(rt)].r - tree[R(rt)].l + 1) / 2;
        tree[rt].f = 0;
        tree[rt].d = 0;
    }
}
void pushup(int rt) {
    tree[rt].sum = tree[L(rt)].sum + tree[R(rt)].sum;
}
void update(int l,int r,int rt,int f) {
    if(l == tree[rt].l && r == tree[rt].r) {
        tree[rt].d ++;
        tree[rt].f += f;
        tree[rt].sum += (ll)(f*2 + (tree[rt].r - tree[rt].l))*(ll)(tree[rt].r - tree[rt].l + 1)/2;
        return ;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(r <= mid) {
        update(l,r,L(rt),f);
    } else if(l >= mid + 1) {
        update(l,r,R(rt),f);
    } else {
        update(l,mid,L(rt),f);
        update(mid+1,r,R(rt),f + tree[L(rt)].r - l + 1);
    }
    pushup(rt);
}
ll query(int l,int r,int rt) {
    if(l == tree[rt].l && r == tree[rt].r) {
        return tree[rt].sum;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(r <= mid) {
        return query(l,r,L(rt));
    } else if(l >= mid + 1) {
        return query(l,r,R(rt));
    } else {
        return query(l,mid,L(rt)) + query(mid+1,r,R(rt));
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    int cas = 1;
    while(scanf("%d %d",&n,&m) != EOF) {
        printf("Case %d:\n",cas ++);
        build(1,n,1);
        while(m --) {
            scanf("%d %d %d",&op,&a,&b);
            if(op == 0) {
                printf("%lld\n",query(a,b,1));
            } else {
                update(a,b,1,1);
            }
            //srep(i,n) printf("%d ",query(i,i,1)); cout<<endl;
        }
    }  
	return 0;
}

