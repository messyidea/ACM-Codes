
/***********************************************\
 |Author: messyidea
 |Created Time: 2014-7-31 12:22:18
 |File Name: 1006.cpp
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
int n,m;
struct Tree{
    int l,r,now;
}tree[maxn<<2];
int data[maxn];
int fin[maxn];
int tot = 0;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
void pushup(int rt){
    if(tree[L(rt)].now == tree[R(rt)].now){
        tree[rt].now = tree[L(rt)].now;
    } else {
        tree[rt].now = -1;
    }
}
void build(int l,int r,int rt){
    tree[rt].l = l;tree[rt].r = r;
    tree[rt].now = -1;
    if(l == r){
        tree[rt].now = data[l-1];
        //cout<<tree[rt].now<<endl;
        return ; 
    }
    int mid = (l+r)>>1;
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
    pushup(rt);
}
void up1(int x,int y,int v,int rt){
    int l = tree[rt].l,r = tree[rt].r;
    if(x <= l && y >= r){
        tree[rt].now = v;
        return ;
    }
    if(tree[rt].now != -1){
        tree[L(rt)].now = tree[R(rt)].now = tree[rt].now;
        tree[rt].now = -1;
    }
    int mid = (l+r)>>1;
    if(mid >= y) up1(x,y,v,L(rt));
    else if(x >= mid + 1) up1(x,y,v,R(rt));
    else {
        up1(x,mid,v,L(rt));
        up1(mid+1,y,v,R(rt));
    }
    pushup(rt);
}
void up2(int x,int y,int v,int rt){
    int l = tree[rt].l,r = tree[rt].r;
    if(x <= l && y >= r){
        if(tree[rt].now != -1){
            if(tree[rt].now > v)
                tree[rt].now = gcd(tree[rt].now,v);
            return ;
        }
    }
    if(tree[rt].now != -1) {
        tree[L(rt)].now = tree[R(rt)].now = tree[rt].now;
        tree[rt].now = -1;
    }
    int mid = (l+r)>>1;
    if(mid >= y) up2(x,y,v,L(rt));
    else if(x >= mid + 1) up2(x,y,v,R(rt));
    else {
        up2(x,mid,v,L(rt));
        up2(mid+1,y,v,R(rt));
    }
    pushup(rt);
}
void query(int x,int y,int rt){
    int l =tree[rt].l,r = tree[rt].r;
    if(x <= l && y >= r){
        if(tree[rt].now != -1){
            for(int i = l;i<=r;i++){
                fin[tot++] = tree[rt].now;
            }
            return ;
        }
    }
    int mid = (l+r)>>1;
    if(mid >= y) query(x,y,L(rt));
    else if(x >= mid+1) query(x,y,R(rt));
    else {
        query(x,mid,L(rt));
        query(mid+1,r,R(rt));
    }
}
int main() {
    //freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int a,b,c,d;
    while(T--){
        scanf("%d",&n);
        rep(i,n) scanf("%d",&data[i]);
        build(1,n,1);
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(a == 1){
                up1(b,c,d,1);
            } else {
                up2(b,c,d,1);
            }
        }
        tot = 0;
        query(1,n,1);
        for(int i=0;i<tot;++i){
            printf("%d ",fin[i]);
        }
        printf("\n");
    }
    return 0;
}
