
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 100007;
//函数线段书
int L[M * 40], R[M * 40], sum[M * 40];
long long jg[M *40];
int tot;
int b[M * 40];
struct edge{
    int l, r, d;
}edg[M * 40];
bool cmp(edge a, edge b){
    return a.d < b.d;
}
int ccc = 10;
void build(int l, int r, int &t){
    t = ++tot;
    sum[t] = 0;
    jg[t] = 0;
    if(l >= r) return;
    int m = (l + r) >> 1;
    build(l, m, L[t]);
    build(m + 1, r, R[t]);
}
void update(int pre, int &t, int l, int r, int x, int val, int vval){
    t = ++tot;
    L[t] = L[pre], R[t] = R[pre], sum[t] = sum[pre] + val;
    jg[t] = jg[pre] + vval;
    if(l >= r) return;
    int m = (l + r) >> 1;
    if(x <= m) update(L[pre], L[t], l, m, x, val, vval);
    else update(R[pre], R[t], m + 1, r, x, val, vval);
}
long long query(int t, int l, int r, int x){
    if(l >= r) return jg[t];
    if(r <= x) return jg[t];
    int m = (l + r) >> 1;
    long long ans = 0;
    if(l <= x) ans += query(L[t], l, m, x);
    if(m < x) ans += query(R[t], m + 1, r, x);
    return ans;
}
long long query2(int t, int l, int r, int x){
    if(l >= r) return sum[t];
    if(r <= x) return sum[t];
    int m = (l + r) >> 1;
    long long ans = 0;
    if(l <= x) ans += query2(L[t], l, m, x);
    if(m < x) ans += query2(R[t], m + 1, r, x);
    return ans;
}
int main(){
    //freopen("input.txt","r",stdin);
    int n, m, x, p;
    while(~scanf("%d%d%d%d", &n, &m, &x, &p)){
        tot = 0;
        for(int i = 0; i < n; i++)
            scanf("%d%d%d", &edg[i].l, &edg[i].r, &edg[i].d);
        sort(edg, edg + n, cmp);
        build(1, M, b[0]);
        for(int i = 1; i <= n; i++){
            update(b[2 * i - 2], b[2 * i - 1], 1, M, edg[i - 1].l, 1, edg[i - 1].d);
            update(b[2 * i - 1], b[2 * i], 1, M, edg[i - 1].r + 1, -1,-edg[i - 1].d);
        }
        int x, aa, bb, cc;
        long long pre = 1;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d%d", &x, &aa, &bb, &cc);
            long long k = (aa * pre + bb) % cc;
            int ll = 0, rr = n;
            int pos;
            while(ll <= rr){        //在第k条线段加入前x所拥有的线段数。
                int mid = (ll + rr) >> 1;
                long long fh = query2(b[mid * 2], 1, M, x);
                if(fh >= k){
                    rr = mid - 1;
                    pos = mid;
                }else ll = mid + 1;
            }
            if(ll == n + 1)
                pos = 2 * n - 2;
            else pos *= 2;
            long long as = query(b[pos], 1, M, x);
            if(pre > p) as *= 2;
            pre = as;
            printf("%I64d\n", as);
        }
    }
    return 0;
}
