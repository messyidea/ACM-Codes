/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/14 20:30:14
 |File Name: Connect_them.cpp
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
int n;
int da[105][105];
bool vis[105];
struct PP{
    int a,b,c;
}pp[10005];
PP an[10005];
int tot2;
int tot;
int fa[105];
void init() {
    for(int i=0;i<=n;++i) fa[i] = i;
}
bool cmp(PP a,PP b) {
    if(a.c != b.c) return a.c < b.c;
    if(a.a != b.a) return a.a < b.a;
    return a.b < b.b;
}
int find(int a) {
    return fa[a] = fa[a] == a ? a : find(fa[a]);
}
bool merge(int x,int y) {
    int xx = find(x);
    int yy = find(y);
    if(xx == yy) return false;
    fa[xx] = yy;
    return true;
}
bool cmp2(PP a,PP b) {
    if(a.a != b.a) return a.a < b.a;
    return a.b<b.b;
}
int krus() {
    init();
    sort(pp,pp+tot,cmp);
    int now = 1;
    tot2 = 0;
    rep(i,tot) {
        int u = pp[i].a;
        int v = pp[i].b;
        if(merge(u,v)) {
            now ++;
            an[tot2 ++] = pp[i];
            if(now == n) break;
        }
    }
    if(now != n) return -1;
    sort(an,an+tot2,cmp2);
    return 1;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        tot = 0;
        PP tp;
        rep(i,n) {
            rep(j,n) {
                scanf("%d",&da[i][j]);
            }
        }
        rep(i,n) {
            for(int j=0;j<i;++j) {
                if(da[i][j] != 0) {
                    tp.a = j+1;
                    tp.b = i+1;
                    tp.c = da[i][j];
                    pp[tot ++] = tp;
                    //cout<<tp.a<<"  "<<tp.b<<"  "<<tp.c<<endl;
                }
            }
        }
        int ans = krus();
        if(ans == -1)
            printf("%d\n",ans);
        else {
            printf("%d %d",an[0].a,an[0].b);
            for(int i=1;i<tot2;++i) {
                printf(" %d %d",an[i].a,an[i].b);
            }
            puts("");
        }
    }
	return 0;
}

