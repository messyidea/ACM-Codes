
/***********************************************\
 |Author: YMC
 |Created Time: 2014-7-6 13:31:57
 |File Name: aa.cpp
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

using namespace std;
#define maxn 100010
#define maxx 400010
#define LL long long 
#define rep(i,n) for(int i=0;i<n;++i)
int n,m;
int a,b;
int ll[maxx];
LL num[maxn];
int pos;
struct Plane{
    int x,y;
}plane[maxn];
struct Block{
    int x,y,z;
	int idx;
}block[maxn];
struct Tree{
    int l,r,cnt,idx;
}tree[maxx<<2];
void build(int l,int r,int rt){
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].idx = -1;
    tree[rt].cnt = 0;
    if(l + 1 == r) return ;
    int mid = (l+r)>>1;
    build(l,mid,L(rt));
    build(mid,r,R(rt));
}
bool cmp1(Block a,Block b){
    return a.z < b.z;
}
void update(int l,int r,int idx,int rt){
    if(ll[tree[rt].l] >= l && ll[tree[rt].r] <= r){
        tree[rt].idx = idx;
        return ;
    }
    if(tree[rt].l + 1 == tree[rt].r) return ;
    if(tree[rt].idx != -1){
        tree[L(rt)].idx = tree[rt].idx;
        tree[R(rt)].idx = tree[rt].idx;
        tree[rt].idx = -1;
    }
    int mid = (tree[rt].l + tree[rt].r)>>1;
    if(ll[mid] >= r) update(l,r,idx,L(rt));
    else if(l >= ll[mid]) update(l,r,idx,R(rt));
    else{
        update(l,ll[mid],idx,L(rt));
        update(ll[mid],r,idx,R(rt));
    }
    /*if(tree[L(rt)].idx == tree[R(rt)].idx){
    	tree[rt].idx = tree[L(rt)].idx;
    	tree[L(rt)].idx = tree[R(rt)].idx = -1;
	}*/
    
}
void query(int l,int r,int rt){
    if(ll[tree[rt].l] >= l && ll[tree[rt].r] <= r){
        tree[rt].cnt ++;
        return ;
    }
    if(tree[rt].l + 1 == tree[rt].r) return ;
    if(tree[rt].cnt > 0) {
    	tree[L(rt)].cnt += tree[rt].cnt;
    	tree[R(rt)].cnt += tree[rt].cnt;
    	tree[rt].cnt = 0;
    }
    int mid = (tree[rt].l + tree[rt].r)>>1;
    if(ll[mid] >= r) query(l,r,L(rt));
    else if(ll[mid] <= l) query(l,r,R(rt));
    else{
        query(l,ll[mid],L(rt));
        query(ll[mid],r,R(rt));
    }
}
void solve(int l,int r,int rt){
	if(l+1 == r){
		if(tree[rt].idx != -1) num[tree[rt].idx] += (long long)(ll[tree[rt].r] - ll[tree[rt].l]) * (long long )tree[rt].cnt;
		return ;
	}
	if(tree[rt].cnt > 0){
		tree[L(rt)].cnt += tree[rt].cnt;
		tree[R(rt)].cnt += tree[rt].cnt;
		tree[rt].cnt = 0;
	}
	if(tree[rt].idx != -1){
		tree[L(rt)].idx = tree[R(rt)].idx = tree[rt].idx;
	}
	int mid = (l + r) >> 1;
	solve(l,mid,L(rt));
	solve(mid,r,R(rt));
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d%d",&n,&m)!=EOF){
        pos = 0;
        rep(i,n){
            scanf("%lld%lld",&plane[i].x,&plane[i].y);
            ll[pos++] = plane[i].x;
            ll[pos++] = plane[i].y;
        }
        rep(i,m){
            scanf("%d%d%d",&block[i].x,&block[i].y,&block[i].z);
            block[i].idx = i+1;
            ll[pos++] = block[i].x;
            ll[pos++] = block[i].y;
        }
        sort(block,block+m,cmp1);
        sort(ll,ll+pos);
        int len = unique(ll,ll+pos)-ll-1;
        build(0,len,1);
        rep(i,m){
            update(block[i].x,block[i].y,block[i].idx,1);
        }
        memset(num,0,sizeof(num));
        rep(i,n){
            query(plane[i].x,plane[i].y,1);
        }
        solve(0,len,1);
        for(int i=1;i<=m;++i){
         	printf("%lld\n",num[i]);
        }
        printf("\n");
    }
	return 0;
}
