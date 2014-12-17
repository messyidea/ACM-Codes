//dp[i][j]  i步在j点的概率
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;

const int MAXV = 55;
const int MAXE = MAXV * MAXV;
const int MAXD = 10010;
const double EPS = 1e-12;

int head[MAXV], outdeg[MAXV], ecnt;
int to[MAXE], next[MAXE];
int n, m, T, d;

#define FOR(i, n) for(int i = 1; i <= n; ++i)
struct Mat {
    double mat[MAXV][MAXV];
    void clear() {
        FOR(i, n) FOR(j, n) mat[i][j] = 0;
    }
    void one() {
        FOR(i, n) FOR(j, n) mat[i][j] = (i == j);
    }
    Mat operator * (const Mat& rhs) const {
        Mat res; res.clear();
        FOR(i, n) FOR(k, n) {
            if(mat[i][k] < EPS) continue;
            FOR(j, n) res.mat[i][j] += mat[i][k] * rhs.mat[k][j];
        }
        return res;
    }
};

Mat power(Mat x, int p) {
    Mat res; res.one();
    while(p) {
        if(p & 1) res = res * x;
        x = x * x;
        p >>= 1;
    }
    return res;
}

void init() {
    memset(head + 1, -1, n * sizeof(int));
    memset(outdeg + 1, 0, n * sizeof(int));
    ecnt = 0;
}

void add_edge(int u, int v) {
    outdeg[u]++;
    to[ecnt] = v; next[ecnt] = head[u]; head[u] = ecnt++;
    outdeg[v]++;
    to[ecnt] = u; next[ecnt] = head[v]; head[v] = ecnt++;
}

Mat ans;

double solve(int fail) {
    ans.clear();
    for(int u = 1; u <= n; ++u) if(u != fail) {
        double t = 1.0 / outdeg[u];
        for(int p = head[u]; ~p; p = next[p]) {
            int v = to[p];
            ans.mat[u][v] += t;
        }
    }
    ans = power(ans, d);
    double res = 0;
    for(int i = 1; i <= n; ++i) if(i != fail) {
        for(int j = 1; j <= n; ++j) if(j != fail)
            res += ans.mat[i][j];
    }
    return res / n;
}

void solve() {
    for(int i = 1; i <= n; ++i) {
        printf("%.10f\n", solve(i));
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &d);
        init();
        for(int i = 0, u, v; i < m; ++i) {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
        }
        solve();
    }
}
