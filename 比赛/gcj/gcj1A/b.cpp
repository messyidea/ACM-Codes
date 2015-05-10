/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/18 9:59:11
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
ll n,m;
ll da[1005];
ll t;
int cas = 1;
priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
ll test(ll mid) {
    ll ans = 0;
    for(int i=1;i<=n;++i) ans += mid / da[i];
    return ans;
}
ll test2(ll mid) {
    ll ans = 0;
    srep(i,n) {
        if(mid % da[i] == 0) ans += mid/da[i];
        else ans += mid/da[i] +1;
    }
    return ans;
}
void solve() {
    ll l = 0, r = 100000*m;
    ll mid;
    ll now;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        now = test2(mid);
        if(now >= m) r = mid-1;
        else {
            l = mid;
        }
    }
    m -= test2(l);
    while(!pq.empty()) pq.pop();
    l ++;
    srep(i,n) {
        if(da[i] == 1) {
            pq.push(MP(0,i));
            continue;
        }
        if(l % da[i] <= 1) {
            pq.push(MP(1 - l % da[i],i));
        } else {
            pq.push(MP(da[i] + 1 - l % da[i],i));
        }
    }
    pair<ll,int> tp;
    srep(i,m-1) {
        tp = pq.top();
        pq.pop();
        tp.first += da[tp.second];
        pq.push(tp);
    }
    tp = pq.top();
    printf("Case #%d: %d\n",cas ++,tp.second);
}
int main() {
	freopen("B-large-practice.in","r",stdin); 
	freopen("out.txt","w",stdout); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld %lld",&n,&m);
        srep(i,n) scanf("%lld",&da[i]);
        solve();
    }
	return 0;
}

