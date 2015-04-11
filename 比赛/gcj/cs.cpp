/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/11 11:28:10
 |File Name: cs.cpp
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
priority_queue<int> pq;
int n,t,a,b;
int now;
int da[10005];
inline int solve(int t,int t2) {
    int ans = inf;
    int pos = 1;
    for(int i=1;i*i <= t;++i) {
        int p = t/i;
        if(p * i != t) p++;
        int tp = max(p,t2) + i-1;
        if(tp <= ans) {
            ans = tp;
            pos = i;
        }
    }
    return pos;
}
int main() {
	freopen("B-small-attempt1.in","r",stdin); 
    freopen("bbs.out","w",stdout);
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--) {
        scanf("%d",&n);
        while(!pq.empty()) pq.pop();
        rep(i,n) {
            scanf("%d",&da[i]);
            pq.push(da[i]);
        }
        now = 0;
        int ans = inf;
        while(1) {
            int t = pq.top();
            //cout<<"t == "<<t<<endl;
            ans = min(ans, now + t);
            if(now > ans) break;
            pq.pop();
            int ci = solve(t,pq.empty()?0:pq.top());
            int tp = t / ci;
            if(ci == 1) break;
            now += ci-1;
            int cc = t - tp*ci;
            int cd = ci - cc;
            while(cd --) {
                pq.push(tp);
            }
            while(cc --) {
                pq.push(tp + 1);
            }
        }
        //cout<<"ans == "<<ans<<endl;
        while(!pq.empty()) pq.pop();
        rep(i,n) pq.push(da[i]);
        int ans2 = inf;
        now = 0;
        while(1) {
            int t = pq.top();
            ans2 = min(ans2, now + t);
            if(now > t) break;
            now ++;
            pq.pop();
            pq.push(t/2);
            pq.push(t-t/2);
        }
        //cout<<ans<<"   "<<ans2<<endl;
        printf("Case #%d: %d\n",cas ++, min(ans,ans2));
    }
	return 0;
}

