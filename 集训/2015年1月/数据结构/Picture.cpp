/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-20 15:40:04
 |File Name: picture.cpp
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

using namespace std;

const int N = 10010;
int n,m;
struct line{
    int x,y1,y2,cover;
};
line ll[N];
struct Tree{
    int l,r,cover,num,lb,rb,len;
}tree[N<<2];
int yy[N];
int sum;
bool mysort(line a,line b){
    if(a.x != b.x) 
        return a.x<b.x;
    return a.cover > b.cover;
}
void build(int l,int r,int rt){
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].cover = 0;
    tree[rt].num = 0;
    tree[rt].len = 0;
    if(l + 1== r) return ;   
    int mid = (l+r)>>1;
    build(l,mid,L(rt));
    build(mid,r,R(rt));
}
void update(int rt){
    if(tree[rt].cover > 0) {
        tree[rt].len = yy[tree[rt].r] - yy[tree[rt].l];
        tree[rt].num = tree[rt].lb = tree[rt].rb = 1;       
    }
    else if(tree[rt].l + 1 == tree[rt].r){
        tree[rt].len = 0;
        tree[rt].num = tree[rt].lb = tree[rt].rb = 0;
    }
    else{
        tree[rt].len = tree[L(rt)].len + tree[R(rt)].len;
        tree[rt].lb = tree[L(rt)].lb;
        tree[rt].rb = tree[R(rt)].rb;
        tree[rt].num = tree[L(rt)].num + tree[R(rt)].num - tree[L(rt)].rb*tree[R(rt)].lb;   
    }
}
void query(int a,int b,int cover,int rt){
    int l = tree[rt].l;int r = tree[rt].r;
    if(yy[l]==a && yy[r]==b){
         tree[rt].cover += cover;
         update(rt);
         return ; 
    }
    int mid = (l+r)>>1; 
    if(b <= yy[mid]) query(a,b,cover,L(rt));
    else if(a >= yy[mid]) query(a,b,cover,R(rt));
    else{
        query(a,yy[mid],cover,L(rt));
        query(yy[mid],b,cover,R(rt));
    }
    update(rt);
}
int main() {
	//freopen("input.txt","r",stdin);
    int x1,x2,y1,y2,co,cnt; 
    
    while(~scanf("%d",&n)){
        cnt = 0;
        while(n--){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            ll[cnt].x = x1;ll[cnt].y1 = y1;ll[cnt].y2 = y2;
            ll[cnt].cover = 1;yy[cnt++] = y1;
            ll[cnt].x = x2;ll[cnt].y1 = y1;ll[cnt].y2 = y2;
            ll[cnt].cover = -1;yy[cnt++] = y2;
        }
        sort(ll,ll+cnt,mysort);
        sort(yy,yy+cnt);
        int len = unique(yy,yy+cnt)-yy-1;
        build(0,len,1); 
        int ans = 0,iso = 0,nowlen = 0;
        for(int i=0;i<cnt;++i){
            x1 = ll[i].x;
            y1 = ll[i].y1;
            y2 = ll[i].y2;
            co = ll[i].cover;
            query(y1,y2,co,1);
            if(i > 0) ans += 2*nowlen*(ll[i].x - ll[i-1].x);    
            ans += abs(tree[1].len - iso);            
            iso = tree[1].len;
            nowlen = tree[1].num; 
        }
        printf("%d\n",ans);

    }
	return 0;
}

