/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/15 13:25:30
 |File Name: c.cpp
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

int n,m;
vector <int> ma[100005];
bool vis[100005];
int a,b,c;
void dfs(int u) {
    vis[u] = true;
    for(int i=0;i<ma[u].size();++i) {
        int v = ma[u][i];
        if(!vis[v]) {
            dfs(v);
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;++i) {
            ma[i].clear();
            vis[i] = false;
        }
        rep(i,m) {
            scanf("%d %d",&a,&b);
            ma[a].push_back(b);
            ma[b].push_back(a);
        }
        int count = 0;
        for(int i=1;i<=n;++i) {
            if(!vis[i]) {
                dfs(i);
                count ++;
            }
        }
        printf("%d\n",count - 1);

    }
	return 0;
}

