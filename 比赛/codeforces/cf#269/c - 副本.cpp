/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/27 0:35:37
 |File Name: c.cpp
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
ll n;
ll cal(ll u){
    return (1 + u) * u + (u) * (u-1) / 2;
}
bool solve(ll u){
    if(cal(u) <= n) {
        return true;
    }
    return false;
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(cin>>n)
    {
    ll l = 1;
    //ll r = min(ll(sqrt(n) + 100),n);
    ll r = 1e8;
    
    ll mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(solve(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    int ans = 0;
    if(l > r) swap(l,r);
    if(solve(r)) ans = r;
    else if(solve(l)) ans = l;
    else ans = l-1;
    /*if(solve(l)) ans = l;
    else ans = l-1;*/
    ll t = n - cal(ans);
    if(t % 3 == 0){
        cout<<max(ans - 1,0)<<endl;
        continue;
    }
    if(t % 3 == 2){
        cout<<max(ans - 3,0)<<endl;
        continue;
    }
    if(t % 3 == 1){
        cout<<max(ans - 2,0)<<endl;
        continue;
    }
    }

	return 0;
}

