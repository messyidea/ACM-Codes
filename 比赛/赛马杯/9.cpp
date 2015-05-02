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
struct edge{
    int v,d;
};
edge et;
int tot;
int now;
vector<edge> ma[1000005];
int vis[1000005];
bool visb[2000005];
int dep[1000005];
bool fg;
void dfs(int u) {
    if(fg) return ;
    for(int i=0;i<ma[u].size();++i) {
        et = ma[u][i];
        if(!visb[et.d]) {
            visb[et.d] = true;
            if(vis[et.v] == 0) {
                dep[et.v] = dep[u] + 1;
                vis[et.v] = now;
                dfs(et.v);
            } else if(vis[et.v] == now && dep[et.v] < dep[u]){
                fg = true;
                return ;
            }
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
        srep(i,n) ma[i].clear();
        while(m1--) {
            //scanf("%d %d",&aa,&bb);
            scan_d(aa),scan_d(bb);
            et.v = bb; et.d = tot;
            ma[aa].push_back(et);
            et.v = aa;
            ma[bb].push_back(et);
            tot ++;
        }
        while(m2 --) {
            scan_d(aa),scan_d(bb);
            //scanf("%d %d",&aa,&bb);
            et.v = bb;et.d = tot;
            ma[aa].push_back(et);
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

