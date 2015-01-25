/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-25 13:34:07
 |File Name: Anti_LIS.cpp
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
int dp[1005];
int da[1005];
int pos[1005];
vector <int> ma[1005];
int mx;
void solve() {
    for(int i=0;i<=n;++i) dp[i] = 1;
    for(int i=0;i<=n;++i) ma[i].clear();
    mx = -1;
    for(int i=2;i<=n;++i) {
        for(int j=i-1;j>=1;--j) {
            if(da[j] < da[i]) {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        if(dp[i] > mx) mx = dp[i];
    }

    //srep(i,n) cout<<dp[i]<<"  ";cout<<endl;
    /*int p = mx;
    for(int i=n;i>=0;--i) {
        if(dp[i] == p) {
            pos[p] = i;
            p -- ;
            if(p == 0) {
                break;
            }
        }
    }
    for(int i=1;i<=n;++i) {
        ma[dp[i]].push_back(i);
    }
    int ans = ma[mx].size();
    cout<<ans<<endl;
    cout<<pos[2]<<"  "<<pos[1]<<endl;
    for(int i=mx-1;i>=1;--i) {
        int po = -1;
        for(int k=0;k<ma[i].size();++k) {
            if(ma[i][k] > pos[i+1]) {
                po = k;
                break;
            } 
        }
        if(po == -1) po = ma[i].size();
        ans = min(ans,po);
    }*/
    printf("%d\n",ans);
    
}
int main() {
	freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);;
    while(T--) {
        scanf("%d",&n);
        srep(i,n) scanf("%d",&da[i]);
        solve();
    }
	return 0;
}

