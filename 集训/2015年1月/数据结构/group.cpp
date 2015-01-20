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
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
const int maxn = 100005;
const int mod = 1000000007;
struct Tree{
    int l,r;
    int v;
}tree[maxn << 2];
int n,m;
int a,b;
int c;
void pushup(int rt) {
    tree[rt].v = tree[L(rt)].v + tree[R(rt)].v;
}
void build(int l,int r,int rt) {
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].v = 0;
    if(l == r) {
        return ;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    build(l,mid,L(rt));
    build(mid + 1, r, R(rt));
    tree[rt].v = tree[L(rt)].v + tree[R(rt)].v;
}
void add(int l,int v,int rt) {
    if(l == tree[rt].l && l == tree[rt].r) {
        tree[rt].v += v;
        return ;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= l) {
        add(l,v,L(rt));
    } else if(l >= mid + 1) {
        add(l,v,R(rt));
    } 
    pushup(rt);
} 
int query(int l,int r,int rt) {
    int sum = 0;
    if(l <= tree[rt].l && r >= tree[rt].r) {
        return tree[rt].v;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= r) {
        return query(l,r,L(rt));
    } else if(l >= mid + 1) {
        return query(l,r,R(rt));
    } else {
        sum += query(l,mid,L(rt));
        sum += query(mid+1,r,R(rt));
        return sum;
    }
}
int da[maxn];
bool vis[maxn];
int at[maxn];
struct Ans{
    int l,r,v,id;
}ans[maxn];
bool cmp(Ans a,Ans b) {
    if(a.l != b.l) return a.l < b.l;
    else return a.r < b.r;
}
bool cmp2(Ans a,Ans b) {
    return a.id < b.id;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        memset(vis,false,sizeof(vis));
        scanf("%d %d",&n,&m);
        build(1,n,1);
        srep(i,n) {
            scanf("%d",&da[i]);
            at[da[i]] = i;
        }
        srep(i,m) {
            scanf("%d %d",&ans[i].l,&ans[i].r);
            ans[i].id = i;
        }
        sort(ans+1,ans + 1 + m,cmp);
        int now = 1;
        for(int i=1;i<=n;++i) {
            int val = 1;
            if(vis[da[i] - 1]) val --;
            if(vis[da[i] + 1]) val --;
            vis[da[i]] = true;
            add(i,val,1);
        }
        srep(i,m) {
            while(now < ans[i].l) {
                vis[da[now]] = false;
                if(vis[da[now] + 1])
                    add(at[da[now] + 1],1,1);
                if(vis[da[now] - 1])
                    add(at[da[now] - 1],1,1);
                now ++;
            }
            ans[i].v = query(ans[i].l,ans[i].r,1);
            //printf("%d\n",query(ans[i].l,ans[i].r,1));
        }
        sort(ans+1,ans+1+m,cmp2);
        srep(i,m) {
            printf("%d\n",ans[i].v);
        }
        
    }
	return 0;
}

