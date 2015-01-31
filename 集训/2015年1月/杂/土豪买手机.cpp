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
#define REP(i,n) for(int i=0;i<n;++i)
#define ll long long
ll dp[20][12][12];
ll num[20];
using namespace std;

ll solve(ll n){
    int len = 0;
    memset(dp,-1,sizeof(dp));
    ll nn = n;
    while(n){
        num[len++] = n%10;
        n /= 10;
    }
    if(len == 0) return 0;
    if(len == 1) {
        return nn;
    }
    //cout<<"len == "<<len<<endl;
    ll ans = 0;
    for(int i=0;i<len;++i) {
        if(i == 0) ans += 1;
        else if(i == 1) {
            ans += 9;
        } else if(i == 2) {
            ans += 81;
        } else {
            ans += 81;
        }
    }
    //cout<<"ans == "<<ans<<endl;
    if(len >= 2) {
    	int a = num[len - 1];
	    int b = num[len - 2];
	    for(int i=1;i<=9;++i) {
	        if(i <= a)
	        for(int j=0;j<=9;++j) {
	            if(i == j) continue;
                if(i < a) {
                    ans ++;
                    continue;
                }
	            if(j <= b) {
	                ans ++;
	            }
	        }
	    }
        //cout<<"ans == "<<ans<<endl;
	    bool ff = false;
	    ll now = 0;
        if(a != b) {
	    for(int i=0;i<len;++i) {
	        if(i % 2 == 0)
	        now = now * 10 + a;
	        else now = now * 10 + b;
	    }
	    if(now > nn) ans --;
        }
        bool fg = true;
        for(int i=0;i+2<n;i+=2) {
            if(num[i] != num[i-2]) fg = false;
        }
        for(int i=1;i+2<n;i+=2) {
            if(num[i] != num[i-2]) fg = false;
        }
        if(num[0] == num[1] && fg == true) fg = false;

        if(fg) ans --;

    }
    return ans;
}
int main() {
	freopen("input.txt","r",stdin); 
    int T;
    cin>>T;
    ll tt;
    while(T--) {
        cin>>tt;
        cout<<solve(tt)<<endl;
    }
	return 0;
}

