/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/2 14:05:15
 |File Name: 9.cpp
 |Description: 
\***********************************************/
#pragma comment(linker, "/STACK:102400000,102400000")
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
int n,m1,m2;
int aa,bb;

int tot;
int now;
struct Edge {int v,c,x; }E[3000005];
int l[1000005],e;
void init(int n) {
    srep(i,n) l[i] = -1;
    e = 0;
}
inline void insert(int u,int v,int f,int type){
    if(type == 1) {
        E[e].v = v;E[e].c = f;E[e].x = l[u];l[u] = e++;
        E[e].v = u;E[e].c = f;E[e].x = l[v];l[v] = e++;
    } else {
        E[e].v = v;E[e].c = f;E[e].x = l[u];l[u] = e++;
    }
} 
//vector<pair<int,int> > ma[1000005];
int vis[1000005];
bool visb[2000005];
int dep[1000005];
bool fg;
void dfs(int u) {
    if(fg) return ;
    for(int i=l[u];i>=0;i=E[i].x) {
        if(!visb[E[i].c]) {
            visb[E[i].c] = true;
            if(vis[E[i].v] == 0) {
                dep[E[i].v] = dep[u] + 1;
                vis[E[i].v] = now;
                dfs(E[i].v);
                if(fg) return ;
            } else if(vis[E[i].v] == now && dep[E[i].v] < dep[u]){
                fg = true;
                return ;
            }
            visb[E[i].c] = false;
        }
    }
    //vis[u] = false;
}
//适用于正负整数
template <class T>
inline bool scan_d(T &ret) {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}
 
inline void out(long long x) {
	if(x>9) out(x/10);
	putchar(x%10+'0');
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&n,&m1,&m2);
        int sumb = m1 + m2;
        tot = 0;
        init(n);
        while(m1--) {
            scan_d(aa),scan_d(bb);
            insert(aa,bb,tot,1);
            tot ++;
        }
        while(m2 --) {
            scan_d(aa),scan_d(bb);
            insert(aa,bb,tot,2);
            tot ++;
        }
        for(int i=0;i<=n;++i) {
            vis[i] = 0;
            dep[i] = 0;
        }
        for(int i=0;i<=sumb+4;++i) visb[i] = false;
        fg = false;
        for(int i=n;i>=1;--i) {
            if(vis[i] == 0) {
                now = i;
                dep[i] = 1;
                vis[i] = now;
                dfs(i);
            } else continue;
            if(fg) {
                break;
            }
        }
        if(fg) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
	return 0;
}

