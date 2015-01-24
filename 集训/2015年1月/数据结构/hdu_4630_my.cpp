/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-24 14:58:29
 |File Name: hdu_4630.cpp
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
const int N = 50005;
int da[N],pre[N],ans[N];
int n,m;
vector <int> factor[N];
struct  Que {
    int l,r,id;
}que[N];
struct Tree {
    int l,r,m;
}tree[N<<2];
void init() {
    for(int i=1;i < N;++i) {
        for(int j=i;j < N;j+=i) {
            factor[j].push_back(i);
        }
    }
}
void build(int l,int r,int rt) {
    tree[rt].l = l; tree[rt].r = r;
    tree[rt].m = 0;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
}
bool cmp(Que a,Que b) {
    return a.r < b.r;
}
void update(int l,int val,int rt) {
    tree[rt].m = max(tree[rt].m,val);
    if(tree[rt].l == tree[rt].r) return ;
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= l) update(l,val,L(rt));
    else update(l,val,R(rt));
}
int query(int l,int r,int rt) {
    if(l <= tree[rt].l && r >= tree[rt].r) {
        return tree[rt].m;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= r) return query(l,r,L(rt));
    else if(l >= mid + 1) return query(l,r,R(rt));
    else {
        return max(query(l,mid,L(rt)),query(mid+1,r,R(rt)));
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    init();
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        build(1,n,1);
        srep(i,n) {
            scanf("%d",&da[i]);
        }
        scanf("%d",&m);
        rep(i,m) {
            scanf("%d %d",&que[i].l,&que[i].r);
            que[i].id = i;
        }
        sort(que,que + m,cmp);
        int p = 0;
        memset(pre,0,sizeof(pre));
        for(int i=1;i <= n && p < m; ++i) {
            for(int k=0;k<factor[da[i]].size();++k) {
                int u = factor[da[i]][k];
                if(pre[u] != 0) {
                    update(pre[u],u,1);
                }
                pre[u] = i;
            }
            while(p < m && que[p].r == i) {
                ans[que[p].id] = query(que[p].l,que[p].r,1);
                p ++;
            }
        }
        for(int i=0;i<m;++i) printf("%d\n",ans[i]);
    }

	return 0;
}

