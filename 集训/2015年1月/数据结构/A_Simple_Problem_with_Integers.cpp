/***********************************************\
 |Author: YMC
 |Created Time: 2015/1/22 12:03:47
 |File Name: A_Simple_Problem_with_Integers.cpp
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
const int N = 100005;
struct Tree{
    int l,r;
    __int64 s,add;
}tree[N << 2];
int n,q;

void pushup(int rt) {
    tree[rt].s = tree[L(rt)].s + tree[R(rt)].s;
}
void build(int l,int r,int rt) {
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].add = 0;
    if(l == r){
        scanf("%I64d",&tree[rt].s);
        return ;
    }
    int mid = l + r >> 1;
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
    pushup(rt);
}
char op[15];
void pushdown(int rt) {
    if(tree[rt].add != 0) {
        tree[L(rt)].add += tree[rt].add;
        tree[L(rt)].s += tree[rt].add * (tree[L(rt)].r - tree[L(rt)].l + 1);
        tree[R(rt)].add += tree[rt].add;
        tree[R(rt)].s += tree[rt].add * (tree[R(rt)].r - tree[R(rt)].l + 1);
        tree[rt].add = 0;
    }
}
void update(int l,int r,__int64 v,int rt) {
    if(l <= tree[rt].l && r >= tree[rt].r) {
        tree[rt].add += v;
        tree[rt].s += (tree[rt].r - tree[rt].l + 1) * v;
        return;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= r) update(l,r,v,L(rt));
    else if(l >= mid + 1) update(l,r,v,R(rt));
    else {
        update(l,mid,v,L(rt));
        update(mid+1,r,v,R(rt));
    }
    pushup(rt);
}
__int64 query(int l,int r,int rt) {
    if(l <= tree[rt].l && r >= tree[rt].r) {
        return tree[rt].s;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= r) return query(l,r,L(rt));
    else if(l >= mid + 1) return query(l,r,R(rt));
    else {
        return query(l,mid,L(rt)) + query(mid+1,r,R(rt));
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d %d",&n,&q)) {
        build(1,n,1);
        int a,b;
        __int64 c;
        while(q -- ) {
            scanf("%s",op);
            if(op[0] == 'Q') {
                scanf("%d %d",&a,&b);
                printf("%I64d\n",query(a,b,1));
            } else {
                scanf("%d %d %I64d",&a,&b,&c);
                update(a,b,c,1);
            }
        }
    }
	return 0;
}

