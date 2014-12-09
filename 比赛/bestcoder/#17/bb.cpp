
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#if __cplusplus > 201103L
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#ifdef LOCAL
#define DEBUG
#endif

#define inf 0x3F3F3F3F
#define fst first
#define snd second
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int _end_ = (b), i = (a); i <= _end_; ++i)
#define ROF(i, a, b) for (int _end_ = (b), i = (a); i >= _end_; --i)

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

int64 fpm(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr(T x) {return x * x;}
template <typename T> T gcd(T x, T y) {for (T t; x; ) t = x, x = y % x, y = t; return y; }

template<class edge> struct Graph {
    vector<vector<edge> > adj;
    Graph(int n) {adj.clear(); adj.resize(n + 5);}
    Graph() {adj.clear(); }
    void resize(int n) {adj.resize(n + 5); }
    void add(int s, edge e){adj[s].push_back(e);}
    void del(int s, edge e) {adj[s].erase(find(iter(adj[s]), e)); }
    vector<edge>& operator [](int t) {return adj[t];}
};

vector<int> x[1111];

int count(vector<int> &a, int v) {
    return a.end() - lower_bound(ALL(a), v + 1);
}

int main(int argc, char **argv) {
/*#ifdef LOCAL
    freopen("B.in" , "r", stdin);
    freopen("B.out", "w", stdout);
#endif*/
    freopen("input.txt","r",stdin);
    freopen("out2","w",stdout);
    ios_base::sync_with_stdio(false);

    int T;
    scanf("%d", &T);
    for (; T--; ) {
        int n, k;
        scanf("%d%d", &n, &k);

        vector<int> &tot = x[0];
        tot.clear();
        for (int i = 1; i <= n; ++i) {
            int m;
            scanf("%d", &m);

            x[i].clear();
            for (int j = 1, t; j <= m; ++j) {
                scanf("%d", &t);
                tot.push_back(t);
                x[i].push_back(t);
            }
            sort(ALL(x[i]));
        }

        sort(ALL(tot));

        int64 ans = 0;
        for (int i = 1; i <= n; ++i) {
            int t = SZ(x[i]);
            for (int j = 0; j < t; ++j) {
                int v = x[i][j];
                ans += count(x[0], k - v) - count(x[i], k - v);
            }
        }
        printf("%I64d\n", ans / 2);
    }

    return 0; 
}
