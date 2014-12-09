/***********************************************\
 |Author: YMC
 |Created Time: 2014-7-29 15:21:06
 |File Name: 1007.cpp
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
#define maxn 100005
struct Tree{
    int l,r;
    ll sf,sy;
    int lazy;
}tree[maxn<<2];
ll fb[100] ;
ll cal(ll x){
    if(x <= 1) return 1;
    for(int i=0;i<93;++i){
        if(fb[i] > x){
            if(i >= 1){
            	//return fb[i-1];
            	if(x-fb[i-1]<=fb[i]-x) return fb[i-1];
            	else return fb[i];
            }
            else return 1;
        }
    }
    return fb[92];
}
void pushup(int rt){
    tree[rt].sf = tree[L(rt)].sf + tree[R(rt)].sf;
    tree[rt].sy = tree[L(rt)].sy + tree[R(rt)].sy;
    if(tree[rt].l == tree[rt].r) return ;
    else {
        if(tree[L(rt)].lazy == tree[R(rt)].lazy){
            tree[rt].lazy = tree[L(rt)].lazy;
        } else {
            tree[rt].lazy == -1;
        }
    }
}
void build(int l,int r,int rt){
    tree[rt].l = l;tree[rt].r = r;
    tree[rt].lazy = 1;
    if(l == r){
        tree[rt].sf = 1;
        tree[rt].sy = 0;
        return ;
    }
    int mid = (l+r)>>1;
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
    pushup(rt);
}
void add(int a,ll b,int rt){
    int l = tree[rt].l,r = tree[rt].r;
    if(l == r){
        if(tree[rt].lazy == 1){
            tree[rt].sy += b;
            tree[rt].sf = cal(tree[rt].sy);
        } else {
            tree[rt].sy = tree[rt].sf + b;
            tree[rt].sf = cal(tree[rt].sy);
            tree[rt].lazy = 1;
        }
        return ;
    }
    if(tree[rt].lazy != -1) {
    	tree[L(rt)].lazy = tree[R(rt)].lazy = tree[rt].lazy;
    	tree[rt].lazy = -1;
    }
    int mid = (tree[rt].l+tree[rt].r)>>1;
    if(a <= mid) add(a,b,L(rt));
    else add(a,b,R(rt));
    pushup(rt);
}
void update(int x,int y,int rt){
    int l = tree[rt].l,r = tree[rt].r;
    if(l >= x && y >= r){
        tree[rt].lazy = 2;
        return ;
    }
    if(tree[rt].lazy != -1){
        tree[L(rt)].lazy = tree[R(rt)].lazy = tree[rt].lazy;
        tree[rt].lazy = -1;
    }
    int mid = (l+r)>>1;
    if(y <= mid) update(x,y,L(rt));
    else if(x >= mid+1) update(x,y,R(rt));
    else {
        update(x,mid,L(rt));
        update(mid+1,y,R(rt));
    }
    pushup(rt);
}
ll query(int x,int y,int rt){
    ll ans = 0;
    int l = tree[rt].l,r = tree[rt].r;
    if(l >= x && y >= r){
        if(tree[rt].lazy == 1) return tree[rt].sy;
        if(tree[rt].lazy == 2) return tree[rt].sf;
    }
    if(tree[rt].lazy!=-1){
    	tree[L(rt)].lazy = tree[R(rt)].lazy = tree[rt].lazy;
    	tree[rt].lazy = -1;
	}
    int mid = (l + r )>>1;
    if(mid >= y) ans += query(x,y,L(rt));
    else if(mid + 1 <= x) ans += query(x,y,R(rt));
    else {
        ans += query(x,mid,L(rt));
        ans += query(mid+1,y,R(rt));
    }
    return ans;
}
void pre(){
    fb[1] = 1;fb[2] = 1;
    for(int i=3;i<93;++i){
        fb[i] = fb[i-1] + fb[i-2];
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    pre();
    int n,m;
    int a,b;
    ll c;
    while(~scanf("%d%d",&n,&m)){
        build(1,n,1);
        while(m--){
            scanf("%d%d%lld",&a,&b,&c);
            if(a == 1){
                add(b,c,1);
            } else if (a == 2){
                printf("%I64d\n",query(b,c,1));
            } else {
                update(b,c,1);
            }
        }
    }
	return 0;
}

