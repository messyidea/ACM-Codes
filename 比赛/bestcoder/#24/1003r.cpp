
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

typedef __int64 ll;
const int MOD = 2333333;
const int N = 50000+5;

int mo[20] = {2333333,2196720,580608,165888,55296,18432,
6144,2048,1024,512,256,128,64,32,16,8,4,2,1};
int pow2[33];

vector<ll> vt[N];
struct Segtree {
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
    ll mark[N<<2];
    int length[N<<2], sum[N<<2];
    void build(int rt, int l, int r) {
        mark[rt] = 0;
        length[rt] = r-l+1;
        if(l == r) {
            vt[l].clear();
            int x;
            scanf("%d", &x);
            vt[l].push_back(x);
            sum[rt] = x%MOD;
            return ;
        }
        int mid = l+r>>1;
        build(lson); build(rson);
        up(rt);
    }

    inline void Add(int &x, int y) {
        x += y;
        if(x >= MOD)    x -= MOD;
    }

    void up(int rt) {
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
        Add(sum[rt], 0);
    }

    void down(int rt) {
        if(mark[rt]) {
            mark[rt<<1] += mark[rt];
            mark[rt<<1|1] += mark[rt];
            Add(sum[rt<<1], 1LL*length[rt<<1]*mark[rt]%MOD);
            Add(sum[rt<<1|1], 1LL*length[rt<<1|1]*mark[rt]%MOD);
            mark[rt] = 0;
        }
    }

    void update(int rt, int l, int r, int L, int R, int v) {
        if(L <= l && R >= r) {
            mark[rt] += v;
            Add(sum[rt], 1LL*length[rt]*v%MOD);
            return ;
        }
        down(rt);
        int mid = l+r>>1;
        if(L <= mid)    update(lson, L, R, v);
        if(R > mid) update(rson, L, R, v);
        up(rt);
    }

    int pow_mod(int x, int n, int mod) {
        int ret = 1%mod;
        while(n) {
            if(n&1) ret = 1LL*ret*x%mod;
            x = 1LL*x*x%mod;
            n >>= 1;
        }
        return ret;
    }

    int cal(vector<ll> &v) {
        if(v.size() < 19) {
            int pos = v.size()-1;
            ll ret = v[0];
            bool flag = false;
            if(v[0] >= mo[pos]) {
                flag = true;
                ret = ret%mo[pos] + mo[pos];
            }
            pos--;
            for(int i = 1;i < v.size(); i++) {
                if(flag) {
                    ret = (pow_mod(2, ret, mo[pos]) +v[i])%mo[pos] + mo[pos];
                }
                else {
                    if(ret >= 30) {
                        flag = true;
                        ret = (pow_mod(2, ret, mo[pos]) + v[i])%mo[pos]+mo[pos];
                    }
                    else if(pow2[ret] >= mo[pos]) {
                        flag = true;
                        ret = (pow_mod(2, ret, mo[pos]) + v[i])%mo[pos] + mo[pos];
                    }
                    else {
                        ret = pow2[ret] + v[i];
                        if(ret >= mo[pos]) {
                            flag = true;
                            ret = ret%mo[pos] + mo[pos];
                        }
                    }
                }
                pos--;
            }
            return ret%MOD;
        }
        else {
            ll ret = 1;
            int pos = 18;
            bool flag = true;
            for(int i = v.size()-18;i < v.size(); i++) {
                ret = (pow_mod(2, ret, mo[pos]) + v[i])%mo[pos] + mo[pos];
                pos--;
            }
            return ret%MOD;
        }
    }

    void modify(int rt, int l, int r, int x) {
        if(l == r) {
            if(mark[rt]) {
                vt[l][vt[l].size()-1] += mark[rt];
                mark[rt] = 0;
            }
            vt[l].push_back(0);
            sum[rt] = cal(vt[l]);
            return ;
        }
        down(rt);
        int mid = l+r>>1;
        if(x <= mid)    modify(lson, x);
        else    modify(rson, x);
        up(rt);
    }

    int query(int rt, int l, int r, int L, int R) {
        if(L <= l && R >= r)    return sum[rt];
        down(rt);
        int mid = l+r>>1, ret = 0;
        if(L <= mid)    Add(ret, query(lson, L, R));
        if(R > mid) Add(ret, query(rson, L, R));
        up(rt);
        return ret;
    }
}tree;

int n, m;

void init() {
    for(int i = 0;i <= 30; i++) pow2[i] = 1<<i;
}

int main() {
    init();
    int op, l, r, x;
    while(scanf("%d%d", &n, &m) == 2) {
        tree.build(1, 1, n);
        while(m--) {
            scanf("%d", &op);
            if(op == 1) {
                scanf("%d%d", &l, &r);
                printf("%d\n", tree.query(1, 1, n, l, r));
            }
            else if(op == 2) {
                scanf("%d", &x);
                tree.modify(1, 1, n, x);
            }
            else {
                scanf("%d%d%d", &l, &r, &x);
                tree.update(1, 1, n, l, r, x);
            }
        }
    }
    return 0;
}
