
/***********************************************\
 |Author: YMC
 |Created Time: 2014-10-7 14:20:13
 |File Name: poj 3667.cpp
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
#define maxn 88888
struct Tree{
    int l,r;
    int lsum,rsum,sum,cover;
}tree[maxn << 2];

void build(int l,int r,int rt) {
    tree[rt].l = l; tree[rt].r = r;
    tree[rt].lsum = tree[rt].rsum = tree[rt].sum = r - l + 1;
    tree[rt].cover = 0;
    if(l == r) {
        return ;
    }
    int mid = l + r >> 1;
    build(l,mid,L(rt));
    build(mid + 1,r,R(rt));
}

int searchs(int u,int rt) {
    if(tree[rt].lsum >= u) return tree[rt].l;
    if(tree[L(rt)].sum >= u) return searchs(u,L(rt));
    if(tree[L(rt)].rsum + tree[R(rt)].lsum >= u) return tree[L(rt)].r - tree[L(rt)].rsum + 1;
    if(tree[R(rt)].sum >= u) return searchs(u,R(rt));
    return -1;
}

void pushdown(int rt) {
    if(tree[rt].cover != -1) {
        tree[L(rt)].cover = tree[R(rt)].cover = tree[rt].cover;
        if(tree[rt].cover == 0) {
            tree[L(rt)].lsum = tree[L(rt)].sum = tree[L(rt)].rsum = tree[L(rt)].r - tree[L(rt)].l + 1;
            tree[R(rt)].lsum = tree[R(rt)].sum = tree[R(rt)].rsum = tree[R(rt)].r - tree[R(rt)].l + 1;
        } else {
            tree[L(rt)].lsum = tree[L(rt)].sum = tree[L(rt)].rsum = 0;
            tree[R(rt)].lsum = tree[R(rt)].sum = tree[R(rt)].rsum = 0;
        }
        tree[rt].cover = -1;
    }
}

void pushup(int rt) {
    if(tree[L(rt)].cover == 0) tree[rt].lsum = tree[L(rt)].sum + tree[R(rt)].lsum;
    else tree[rt].lsum = tree[L(rt)].lsum;

    if(tree[R(rt)].cover == 0) tree[rt].rsum = tree[R(rt)].sum + tree[L(rt)].rsum;
    else tree[rt].rsum = tree[R(rt)].rsum;

    int mid = tree[L(rt)].rsum + tree[R(rt)].lsum;
    int a = max(tree[L(rt)].lsum,tree[R(rt)].rsum);
    int b = max(tree[L(rt)].sum,tree[R(rt)].sum);
    tree[rt].sum = max(max(a,b),mid);

    if(tree[L(rt)].cover == tree[R(rt)].cover) tree[rt].cover = tree[L(rt)].cover;
}

void fre(int x,int y,int rt) {
    int l = tree[rt].l,r = tree[rt].r;
    if(tree[rt].cover == 0) return ;
    if(x <= l && y >= r) {
        tree[rt].cover = 0;
        tree[rt].lsum = tree[rt].rsum = tree[rt].sum = tree[rt].r - tree[rt].l + 1;
        return ;
    }
    if(tree[rt].cover == 1) pushdown(rt);
    int mid = l + r >> 1;
    if(y <= mid) fre(x,y,L(rt));
    else if(x >= mid + 1) fre(x,y,R(rt));
    else {
        fre(x,mid,L(rt));
        fre(mid + 1,y,R(rt));
    }
    pushup(rt);
}

void update(int x,int y,int rt) {
    int l = tree[rt].l,r = tree[rt].r;
    if(x <= l && y >= r) {
        tree[rt].cover = 1;
        tree[rt].lsum = tree[rt].rsum = tree[rt].sum = 0;
        return ;
    }
    pushdown(rt);
    int mid = l + r >> 1;
    if(y <= mid) update(x,y,L(rt));
    else if(x >= mid + 1) update(x,y,R(rt));
    else {
        update(x,mid,L(rt));
        update(mid + 1,y,R(rt));
    }
    pushup(rt);
}

int main() {
	//freopen("input.txt","r",stdin); 
    int n,m,con,a,b;
    char cc;
    while(~scanf("%d %d",&m,&n)) {
        build(1,n,1);
        while(m--) {
            scanf("%c",&cc);
            if(cc == 'A') {
                scanf("%d",&a);
                int tp = searchs(a,1);
                if(tp == -1) {
                    puts("NULL");
                    continue;
                } else {
                    printf("%d\n",tp);
                    update(tp,tp + a - 1,1);
                }
            } else {
                scanf("%d %d",&a,&b);
                fre(a,a + b - 1,1);
            }
        }
    }
	return 0;
}
