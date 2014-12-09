/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/12 10:45:29
 |File Name: dd.cpp
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
vector<int> ma[2005];
int a[2005];
ll num[2005];
ll ans = 0;
int d,n;
#define mod 1000000007
void dfs(int cu,int id,int fa) {
    num[cu] = 1;
    int len = ma[cu].size();
    rep(i,len) {
        int t = ma[cu][i];
        if(a[t] < a[id] || t == fa) continue;
        if(a[t] == a[id] && t > id) {
            dfs(t,id,cu);
            num[cu] = num[cu] * ( num[t] + 1 ) % mod;
            continue;
        }
        if(a[t] > a[id] && a[t] - a[id] <= d) {
            dfs(t,id,cu);
            num[cu] = num[cu] * ( num[t] + 1 ) % mod;
            continue;
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d %d",&d,&n)) {
        srep(i,n) ma[i].clear();
        int l,r;
        srep(i,n) {
            scanf("%d",&a[i]);
        }
        srep(i,n-1) {
            scanf("%d %d",&l,&r);
            ma[l].push_back(r);
            ma[r].push_back(l);
        }
        ans = 0;
        srep(i,n) {
            memset(num,0,sizeof num);
            dfs(i,i,-1);
            ans += num[i];
            ans %= mod;
        }
        printf("%I64d\n",ans);

    }
    
	return 0;
}

