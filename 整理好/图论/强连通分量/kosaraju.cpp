/*==================================================*\
 | Author: ziki
 | Created Time: 
 | File Name: 
 | Description: 
\*==================================================*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>
 
using namespace std;
using namespace rel_ops;
 
typedef long long int64;
typedef long long ll;
typedef unsigned long long uint64;
typedef unsigned long long ull;
const double pi=acos(-1.0);
const double eps=1e-11;
const int inf=0x7FFFFFFF;
template<class T> inline bool checkmin(T &a,T b){return b<a?a=b,1:0;}
template<class T> inline bool checkmax(T &a,T b){return b>a?a=b,1:0;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define mem(a,b) memset(a, b, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define rep(i,n) for(int i=0; i<int(n); i++)
#define repit(i,v) for(typeof(v.begin()) i=v.begin(); i!=v.end(); i++)
#define iter(v) typeof(v.begin())
#define ff first
#define ss second
#define sz(x) int(x.size())
#ifdef LOCAL
#define dbg(args...) printf(args); //##__VA_ARGS__
#define dout cout
#define out(x) (cout<<#x<<": "<<x<<endl)
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}
#else
#define dbg(...)
#define dout if(true);else cout
#define out(...)
#define show(...)
#endif

/*
    Kosaraju's Algorithm
    author:Ziki
    forw 为正向边 back为反向边
    节点编号0..n-1
    调用kosaraju(n)后，
        scc为scc个数
        num[i]为节点scc编号
        sccv存储每个scc所在的节点
        scc按拓扑从大到小排列。
*/

const int MAXV = 1e5+10;
int dfn[MAXV], num[MAXV], scc, cnt;
VI forw[MAXV], back[MAXV];
VI sccv[MAXV];
void dfs(int u) {
    num[u] = -1;
    for(int i=0; i<forw[u].size(); i++) 
        if(num[forw[u][i]] != -1) {
            dfs(forw[u][i]);
        }
    dfn[cnt++] = u;
}

void ndfs(int u) {
    num[u] = scc;
    sccv[scc].push_back(u);
    for(int i=0; i<back[u].size(); i++) {
        if(num[back[u][i]] == -1) {
            ndfs(back[u][i]);
        }
    }
}
void kosaraju(int n) {
    clr(num);
    scc = cnt = 0;
    for(int i=0; i<n; i++) 
        if(!num[i]) dfs(i);
    for(int i=cnt-1; i>=0; i--) {
        if(num[dfn[i]] == -1) {
            sccv[scc].clear();
            ndfs(dfn[i]);
            scc++;
        }
    }
}

int val[MAXV];
const ll mod = 1000000007;
int main() {
    int n, m;
    while (cin >> n) {
        rep(i, n) {
            scanf("%d", val+i);
        }
        cin >> m;
        rep(i, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            forw[u].PB(v);
            back[v].PB(u);
        }
        kosaraju(n);
        ll a1 = 1, a2 = 0;
        for (int i = 0; i < scc; i++) {
            ll m1 = 1e17, m2 = 0;

            for (int j = 0; j < sccv[i].size(); j++) {
                ll t = (ll)val[sccv[i][j]];
                if (t < m1) m1 = t, m2 = 1;
                else if (t == m1) m2 ++;
            }
            a1 = a1 * m2 % mod;
            a2 += m1;
        }
        cout << a2 << ' ' << a1 << endl;
    }
    return 0;
}