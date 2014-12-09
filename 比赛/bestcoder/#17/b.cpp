/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/8 19:39:33
 |File Name: b.cpp
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
ll k;
ll da[1005][105];
int nn[1005];
ll tt[100005];
int tot;
int main() {
	//freopen("input.txt","r",stdin);
    //freopen("out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %I64d",&n,&k);
        tot = 0;
        rep(i,n) {
            scanf("%d",&nn[i]);
            rep(j,nn[i]) {
                scanf("%I64d",&da[i][j]);
                tt[tot ++] = da[i][j];    
            }
            sort(da[i],da[i] + nn[i]);
        }
        if(n == 1) {
            puts("0");
            continue;
        }
        sort(tt,tt+tot);
        int l = 0,r = tot - 1;
        ll le = 0;
        ll ans = 0;
        while(l < r) {
            if(tt[l] + tt[r] > k) {
                r--;
                le++;
            } else {
                ans += le;
                l ++;
            }
        }
        ll f = tot - l - 1;
        ans += (1 + f) * f / 2;
        ll tp = 0;
        ll tp1 = 0;
        for(int i = 0; i < n; ++i) {
            if(nn[i] == 1 || nn[i] == 0) continue;
            l = 0;r = nn[i] - 1;
            tp = 0;
            tp1 = 0;
            le = 0;
            while(l < r) {
                if(da[i][l] + da[i][r] > k) {
                    r --;
                    le ++;
                } else {
                    tp += le;
                    l ++;
                }
            }
            f = nn[i] - l - 1;
            tp += (1 + f) * f / 2;
            ans -= tp; 
        }
        printf("%I64d\n",ans);
    }
	return 0;
}


/*对于一个排好序的数组a[i]
int l = 0,r = size - 1;
while(l < r) {
    if(a[l] + a[r] >= k) {
        r --;m ++;
    } else {
        ans += m;
        l ++;
    }
}
int t = size - l - 1;
ans += (1 + t) * t / 2;*/
