/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/2 0:05:05
 |File Name: Minimizing maximizer.cpp
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
#define L(rt) rt<<1
#define R(rt) rt<<1|1
using namespace std;
#define INF 1<<29
const int N = 50005;
int n;
struct Tree{
    int l,r,minx;
}tree[N<<2];
void build(int l,int r,int rt){
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].minx = INF;
    if(l == r) return ;
    int mid = (l+r)>>1;
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
}
void update(int p,int d,int rt){
    if(tree[rt].minx > d) tree[rt].minx = d;
    if(tree[rt].l == tree[rt].r) return ;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(p <= mid) update(p,d,L(rt));
    else update(p,d,R(rt));
}
int query(int l,int r,int rt){
    if(l == tree[rt].l && r == tree[rt].r){
        return tree[rt].minx;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    int ans,ans1,ans2;
    if(r <= mid){
        ans = query(l,r,L(rt));
    }
    else if(l >= mid+1){
        ans = query(l,r,R(rt));
    }
    else {
        ans1 = query(l,mid,L(rt));
        ans2 = query(mid+1,r,R(rt));
        ans = min(ans1,ans2);
    }
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int m;
    while(scanf("%d%d",&n,&m)!=EOF){
        build(1,n,1);
        update(1,0,1);
        int a,b;
        while(m--){
            scanf("%d%d",&a,&b);
            int tp = query(a,b,1);
            update(b,tp+1,1);
        }
        printf("%d\n",query(n,n,1));
    }
	return 0;
}

